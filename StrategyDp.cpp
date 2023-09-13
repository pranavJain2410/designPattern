#include <iostream>
#include <memory>
using namespace std; 

class KickBehavior
{
    public: 
   virtual ~KickBehavior() = default;
   virtual  void kick() = 0;
};

class TornadoKick : public KickBehavior
{
    public:
    void kick() override
    {
        cout<<"Going for tornado kick...."<<endl;
    }
};

class HighKick : public KickBehavior
{
    public:
    void kick() override
    {
        cout<<"Going for high kick...."<<endl;
    }
};


class JumpBehavior
{
    public:
    virtual ~JumpBehavior() = default;
       virtual void jump() = 0;
};

class HighJump: public JumpBehavior
{
    public:
     void jump() override
     {
        cout<<"Going for high jump....."<<endl;
     }
};

class LongJump: public JumpBehavior
{
    public:
     void jump() override
     {
        cout<<"Going for long jump....."<<endl;
     }
};



class Fighter
{
    protected:
    unique_ptr<KickBehavior> kickBehavior;
    unique_ptr<JumpBehavior> jumpBehavior;

    public:
        // Fighter(unique_ptr<KickBehavior> kick = {}, unique_ptr<JumpBehavior> jump = {})
        // : kickBehavior(std::move(kick)),
        //   jumpBehavior(std::move(jump))
        
        // {

        // }
        void punch()
        {
            cout<<"Default punch...."<<endl;
        }
        void roll()
        {
            cout<<"Default roll...."<<endl;
        }
        void jump()
        {
            jumpBehavior->jump();
        }
        void kick()
        {
            kickBehavior->kick();
        }
        void setKickBehavior(unique_ptr<KickBehavior> kick)
        {
            kickBehavior = std::move(kick);
        }
        void setJumpBehavior(unique_ptr<JumpBehavior> jump)
        {
            jumpBehavior = std::move(jump);
        }

};

class Ken : public Fighter
{
    public:
    Ken(unique_ptr<KickBehavior> kick = {}, unique_ptr<JumpBehavior> jump = {})
          {
                kickBehavior = std::move(kick);
                jumpBehavior = std::move(jump);
          }
    void roll()
    {
        cout<<"Ken special roll....."<<endl;
    }
};



int main()
{
    Ken *k = new Ken(make_unique<TornadoKick>(), make_unique<LongJump>());

    k->jump();
    k->roll();
    k->kick();
    k->punch();

    cout<<"Setting new strategy now ...."<<endl<<endl;


    k->setJumpBehavior(make_unique<HighJump>());
    k->jump();
    return 0;
}