#include<iostream>

using namespace std;

/*声明CPU_Rank*/
enum CPU_Rank{P1 = 1,P2,P3,P4,P5,P6,P7};

class CPU 
{
    private:
        CPU_Rank rank;      //等级
        int frequency;      //频率
        float vlotage;      //电压
    public:
        CPU(CPU_Rank r,int f,float v) 
        {
            rank = r;
            frequency = f;
            vlotage = v;
            cout << "构造一个CPU" <<endl;
        }
        ~CPU() {cout<< "析构一个CPU" <<endl;}

        CPU_Rank GetRank() const { return rank; }
        int GetFrequency() const { return frequency; }
        float GetVlotage() const { return vlotage; }

        void SetRank(CPU_Rank r) {rank = r; }
        void SetFrequency(int f) {frequency = f; }
        void SetVlotage(float v) {vlotage = v; }

        void Run() {cout <<"CPU运行了！"<< endl;}
        void Stop() {cout<< "CPU停止工作了！" <<endl;}
};