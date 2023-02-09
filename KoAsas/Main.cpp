#include <iostream>
#include <windows.h>
#include <thread>


#define info
#define VK_KEY_2	0x32 
#define VK_KEY_3	0x33 
#define VK_KEY_4	0x34
#define VK_KEY_5	0x35
#define VK_KEY_6	0x36 
#define VK_KEY_7	0x37
#define VK_KEY_8	0x38 
#define VK_KEY_R	0x52
#define VK_KEY_V	0x56
POINT hppixel, mppixel;
class Char{
public:
    void pressKey(CHAR keyParam) {
        SHORT key;
        UINT mappedkey;
        INPUT input = { 0 };
        key = VkKeyScan(keyParam);
        mappedkey = MapVirtualKey(LOBYTE(key), 0);
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        input.ki.wScan = mappedkey;
        SendInput(1, &input, sizeof(input));
        Sleep(10);
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));

    }

    void pressKey3rr()
    {

        pressKey(VK_KEY_3);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);

    #ifndef info
        std::cout << "3rr basiyor." << std::endl;
    #endif 

      

    }
    void pressKey4rr()
    {

        pressKey(VK_KEY_4);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
    #ifndef info
        std::cout << "4rr basiyor." << std::endl;
    #endif

    }
    void pressKey5rr()
    {

        pressKey(VK_KEY_5);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
    #ifndef info
        std::cout << "5rr basiyor." << std::endl;
    #endif 

      

    }
    void pressKey6rr()
    {

        pressKey(VK_KEY_6);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
        pressKey(VK_KEY_R);
        Sleep(10);
    #ifndef info
        std::cout << "6rr basiyor." << std::endl;
    #endif 

    }

 
    void press78()

    {

        pressKey(VK_KEY_7);
    
        pressKey(VK_KEY_8);
   
        pressKey(VK_KEY_7);
    #ifndef info
        std::cout << "787 basiyor." << std::endl;
    #endif

 


    }

    void pressf3() {
        INPUT Event = { 0 };
        Event.type = INPUT_KEYBOARD;
        Event.ki.dwFlags = KEYEVENTF_SCANCODE;
        Event.ki.wScan = MapVirtualKey(VK_F3, 0);
        SendInput(1, &Event, sizeof(Event));
        Sleep(15);
        Event.type = INPUT_KEYBOARD;
        Event.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        Event.ki.wScan = MapVirtualKey(VK_F3, 0);
        SendInput(1, &Event, sizeof(Event));
    }

    void cure() {

        pressf3();
        Sleep(15);
        pressKey(VK_KEY_3);
        Sleep(15);
    #ifndef info
        std::cout << "Cure basiyor." << std::endl;
    #endif 

        
    }
    //244,10 hp bar,172,26 mp bar.
    COLORREF renktara(int x,int y) {

        COLORREF color;
        int red, green, blue;

        HDC hDC = GetDC(NULL);
        
        color = GetPixel(hDC, x, y);
       /* red = GetRValue(color);
        green = GetGValue(color);
        blue = GetBValue(color);*/
        return color;
    }

    POINT cursorpos() {

        POINT p;
        GetCursorPos(&p);
        return p;
    }

    void hpmpbas() {
        Sleep(25);
        COLORREF hpbar = renktara(hppixel.x, hppixel.y);
        COLORREF mpbar = renktara(mppixel.x, mppixel.y);
        int hpbarkirmizi = GetRValue(hpbar);
        int mpbarmavi = GetBValue(mpbar);

        if (hpbarkirmizi < 15)
        {
            press78();
        }


        if (mpbarmavi < 15)
        {
            pressKey(VK_KEY_2);
        }
        Sleep(10);
       

    }
    void pressf5() {

        INPUT Event = { 0 };
        Event.type = INPUT_KEYBOARD;
        Event.ki.dwFlags = KEYEVENTF_SCANCODE;
        Event.ki.wScan = MapVirtualKey(VK_F5, 0);
        SendInput(1, &Event, sizeof(Event));
        Sleep(15);
        Event.type = INPUT_KEYBOARD;
        Event.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        Event.ki.wScan = MapVirtualKey(VK_F5, 0);
        SendInput(1, &Event, sizeof(Event));
    }

    void canpotu() {

        pressf5();
        Sleep(15);
        pressKey(VK_KEY_4);
        Sleep(15);
    #ifndef info
        std::cout << "Can Potu basiyor." << std::endl;
    #endif

        
    }


    POINT pixelcandegis() {

        std::cout << "Can barinin istediginiz noktasina imleci goturup 'k' tusuna basiniz.Degeri okudugunda konsolda yazacaktir." << std::endl;

        while (true)
        {
            if (GetKeyState(0x4B) & 0x8000)
            {
                POINT a;
                GetCursorPos(&a);
                std::cout << "Can degeri alindi." << std::endl;
                return a;
                
                break;
            }

            Sleep(50);
        }

    }



    POINT pixelmanadegis() {

        std::cout << "Mana barinin istediginiz noktasina imleci goturup 'k' tusuna basiniz.Degeri okudugunda konsolda yazacaktir." << std::endl;

        while (true)
        {
            if (GetKeyState(0x4B) & 0x8000)
            {
                POINT a;
                GetCursorPos(&a);
                std::cout << "Mana degeri alindi." << std::endl;
                return a;
                
                break;
            }

            Sleep(50);
        }

    }

    bool pixelotosor() {


        std::cout << "Otomatik can mana degeri okutup minor ve mana basmasini istiyormusunuz." << std::endl;
        std::cout << "Evet dediginiz taktirde can ve mana barindan basmasini istediginiz noktanin pixelini okutmaniz istenecektir." << std::endl;
        std::cout << "E/H?" << std::endl;
        char secim;
        std::cin >> secim;

        if (secim=='E' || secim=='e')
        {
            return true;
        }
        else
        {
            
            return false;
        }
    }

    
 
};



void bilgilendirme() {

    std::cout << "Asas Makro Programi" << std::endl;
    std::cout << "________________________________________________________________________________________________" << std::endl;
    std::cout << "1-Light Feet\n2-Mana Potion\n3-Skill\n4-Skill\n5-Skill\n6-Skill\n7-Minor\n8-Minor\nF3(3)-Cure" << std::endl;
    std::cout << "________________________________________________________________________________________________" << std::endl;
    std::cout << "Kullanimi:\n3-4-5-6 tuslarina bastiginizda extradan rr atar(3 e bastiginizda 3rr gibi)\nMouse sag tusa bastiginizda 7878 basar.\nV tusuna bastiginizda ise cure icin f3-3 tusuna basar." << std::endl;
    std::cout << "________________________________________________________________________________________________" << std::endl;

    std::cout << "Capslock tusu aktif oldugunda bot aktif pasif oldugunda bot pasif olur." << std::endl;
}





int main()
{      
    
    hppixel.x = 244;
    hppixel.y = 10;
    mppixel.x = 172;
    mppixel.y = 26;
    Char Char;
    bool sec=Char.pixelotosor();

    if (sec)
    {
        *&hppixel = Char.pixelcandegis();
        Sleep(500);
        getwchar();
        Sleep(500);
        *&mppixel = Char.pixelmanadegis();

        std::cout << "Bot ekrani 5 saniye icinde gelecektir." << std::endl;
        Sleep(5000);
        system("cls");
    }
    else
    {
        std::cout << "Otomatik can ve mana basma aktif degildir." << std::endl;
        std::cout << "Bot ekrani 5 saniye icinde gelecektir." << std::endl;
        Sleep(5000);
        system("cls");
    }

    bilgilendirme();

    

    while (true)
    {
        bool caps_lock_on = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;

        if (caps_lock_on)
        {   
            system("cls");
            bilgilendirme();
            system("Color 0A");
            std::cout << "Bot Aktif....!\n";
            while (true)
            {
                
                if (sec)
                {
                   std::thread t1(&Char::hpmpbas, &Char);
                    t1.join();
                }
                if (GetKeyState(VK_CAPITAL) & 0x8000)
                {
                    bool caps_lock_on = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
                }
                if (GetKeyState(VK_KEY_3) & 0x8000)
                {
                    std::thread t2(&Char::pressKey3rr, &Char);
                    t2.join();
                    Sleep(10);
                }
                if (GetKeyState(VK_RBUTTON) & 0x8000)
                {
                    std::thread t3(&Char::press78, &Char);
                    t3.join();
                }
                if (GetKeyState(VK_KEY_4) & 0x8000)
                {
                    std::thread t4(&Char::pressKey4rr, &Char);
                    t4.join();
                    Sleep(10);
                }
                if (GetKeyState(VK_KEY_5) & 0x8000)
                {
                    std::thread t5(&Char::pressKey5rr, &Char);
                    t5.join();
                    Sleep(10);
                }
                if (GetKeyState(VK_KEY_6) & 0x8000)
                {
                    std::thread t6(&Char::pressKey6rr, &Char);
                    t6.join();
                    Sleep(10);
                }

                if (GetKeyState(VK_KEY_V) & 0x8000)
                {

                    Char.cure();

                }
                if ((GetKeyState(VK_CAPITAL) & 0x0001) == 0)
                {
                    system("cls");
                    bilgilendirme();
                    system("Color 04");
                    std::cout << "Bot Pasif....!\n";
                    
                    break;
                }
                Sleep(10);


            }
        }
      
        Sleep(1000);
    }
    
   
}
