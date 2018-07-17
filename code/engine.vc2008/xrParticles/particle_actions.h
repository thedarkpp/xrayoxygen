//---------------------------------------------------------------------------
#pragma once

namespace PAPI 
{
	// refs
	struct ParticleEffect;
	struct PARTICLES_API			ParticleAction
	{
		enum {
			ALLOW_ROTATE = (1 << 1)
		};
		Flags32 m_Flags;
		PActionEnum type;	// Type field
		ParticleAction() { m_Flags.zero(); }

		virtual void Execute(ParticleEffect *pe, const float dt, float& m_max) = 0;
		virtual void Transform(const Fmatrix& m) = 0;

		virtual void Load(IReader& F) = 0;
		virtual void Save(IWriter& F) = 0;
	};
	
    using PAVec = xr_vector<ParticleAction*>;
    using PAVecIt = PAVec::iterator;
	class ParticleActions{
		PAVec			actions;
		bool			m_bLocked;
        CRITICAL_SECTION m_bLockedGuard;
	public:
						ParticleActions()						{
                            actions.reserve(4);m_bLocked=false;	
                            InitializeCriticalSection(&m_bLockedGuard);
                        }
						~ParticleActions()						{
                            lock();
                            clear();
                            unlock();
                            DeleteCriticalSection(&m_bLockedGuard);
                        }
		void			clear			()
        {
			R_ASSERT(m_bLocked);
			for (PAVecIt it=actions.begin(); it!=actions.end(); it++) 
				xr_delete(*it);
			actions.clear();
		}
		void			append			(ParticleAction* pa)	{R_ASSERT(m_bLocked);actions.push_back(pa);	}
		bool			empty			()						{return	actions.empty();}
		PAVecIt		begin			()						{return	actions.begin();}
		PAVecIt		end				()						{return actions.end();	}
        int			size			()						{return int(actions.size());	}
        void			resize			(int cnt)        		{R_ASSERT(m_bLocked);actions.resize(cnt);	}
        void			copy			(ParticleActions* src);
		void			lock			()						{
            EnterCriticalSection(&m_bLockedGuard);
            R_ASSERT(!m_bLocked);
            m_bLocked=true;
        }
		void			unlock			()						{
            R_ASSERT(m_bLocked);
            m_bLocked = false;
            LeaveCriticalSection(&m_bLockedGuard);
        }
	};
};
