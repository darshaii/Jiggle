#include<windows.h>
#include<iostream>
#include<chrono>

    void movePointer(){
        UINT16 T;
        std::cout<<"PRESS DELETE TO EXIT AFTER GIVING INTERVAL\n\nEnter the time interval (seconds) = ";
        std::cin>>T;
        std::cout<<"\n";

        bool exit;
        bool kill = false;
        int i = 5;
        POINT p;
        SHORT delStatus = GetKeyState(VK_DELETE);

        while(1){
            exit = false;
                INPUT input = {0};
                input.type = INPUT_MOUSE;
                input.mi.dx = i;
                input.mi.dy = i;
                input.mi.dwFlags = MOUSEEVENTF_MOVE;

                std::cout<<".";
                //std::cout<<"X:"<<p->x<<" Y:"<<p->y<<"\n";
                SendInput(1, &input, sizeof(INPUT));
                auto start = std::chrono::high_resolution_clock::now();
                while(exit == false){
                    auto now = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = now-start;
                    if(elapsed.count()>T){exit = true;}
                    if(delStatus != GetKeyState(VK_DELETE)){kill = true; break;}
                    Sleep(500);
                }
            if(kill){break;}
            i = i*(-1);
        }
        std::cout<<"Freeing Memory\n";
}

int main(){    
    movePointer();
    std::cout<<"Returned\n";
    return 0;
    }