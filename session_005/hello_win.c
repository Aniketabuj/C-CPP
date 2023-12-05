#include<Windows.h>
#include<stdio.h>
#include<string.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The standard Window");
    static TCHAR 
}
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

typedef struct StudentInfo
{
    INT iRollNumber;
    TCHAR* szStudentName;
    FLOAT fAttnd;
    TCHAR* szCity;
}STUDENTINFO, *PSTUDENTINFO;

STUDENTINFO strec[] = {
    {1, TEXT("SHUBHAM"), 90.5f, TEXT("Pune")},  
    {2, TEXT("ISHAN"), 89.2f, TEXT("Mumbai")}, 
    {3, TEXT("SALONI"), 92.5f, TEXT("Pune")}, 
    {4, TEXT("ANAGH"), 96.9f, TEXT("Pune")}, 
    {5, TEXT("PRATIK"), 99.6f, TEXT("Jalgaon")}, 
    {6, TEXT("TEJASWINI"), 91.1f, TEXT("Nanded")}, 
    {7, TEXT("NIKITA"), 93.0f, TEXT("Thane")}, 
    {8, TEXT("SHREYAS"), 80.3f, TEXT("Satara")}, 
    {9, TEXT("ADITYA"), 87.2f, TEXT("Yavatmal")}, 
    {10, TEXT("VEENA"), 82.2f, TEXT("Nanded")}, 
    {11, TEXT("MAHENDRA"), 73.2f, TEXT("Solapur")}, 
    {12, TEXT("MAYUR"), 93.7f, TEXT("Solapur")}, 
    {13, TEXT("PAYAL"), 83.8f, TEXT("Kolhapur")}, 
    {14, TEXT("SWATI"), 73.0f, TEXT("Pune")}, 
    {15, TEXT("AKSHAY"), 55.1f, TEXT("Mumbai")}, 
    {16, TEXT("KISHOR"), 28.3f, TEXT("Mumbai")}, 
    {17, TEXT("SATEJ"), 91.9f, TEXT("Thane")}, 
    {18, TEXT("SANDHYA"), 42.0f, TEXT("Thane")}, 
    {19, TEXT("SOMESH"), 98.7f, TEXT("Thane")}, 
    {20, TEXT("SHIVANI"), 51.2f, TEXT("Beed")}, 
    {21, TEXT("GANESH"), 61.1f, TEXT("Nashik")}, 
    {22, TEXT("VAISHNAVI"), 72.3f, TEXT("Nashik")}, 
    {23, TEXT("JAI"), 97.0f, TEXT("Raigad")}, 
    {24, TEXT("PARIKSHIT"), 48.4f, TEXT("Ratnagiri")}, 
    {25, TEXT("MANGESH"), 66.7f, TEXT("Ratnagiri")}, 
    {26, TEXT("RAKESH"), 87.9f, TEXT("Raigad")}, 
    {27, TEXT("AARYA"), 77.1f, TEXT("Sindhudurga")}, 
    {28, TEXT("ONKAR"), 59.4f, TEXT("Sindhudurga")}, 
    {29, TEXT("RISHIKESH"), 63.8f, TEXT("Gadchiroli")}, 
    {30, TEXT("MALLIKARJUN"), 58.8f, TEXT("Akole")},
    {31, TEXT("REVAN"), 72.9f, TEXT("Akole")}, 
    {32, TEXT("MADHURI"), 81.1f, TEXT("Gadchiroli")}, 
    {33, TEXT("KARTIK"), 94.1f, TEXT("Sangli")}, 
    {34, TEXT("UTKARSH"), 97.4f, TEXT("Sangli")}, 
    {35, TEXT("VIVEK"), 89.3f, TEXT("Latur")}, 
    {36, TEXT("NISHA"), 17.7f, TEXT("Hingoli")}, 
    {37, TEXT("SHAHED"), 21.8f, TEXT("Hingoli")}, 
    {38, TEXT("MINAL"), 78.8f, TEXT("Parbhani")}, 
    {39, TEXT("PRATIK"), 99.8f, TEXT("Ahmednagar")}, 
    {40, TEXT("SAMADHAN"), 89.1f, TEXT("Ahmednagar")},
    {41, TEXT("YADNESH"), 82.2f, TEXT("Jalna")}, 
    {42, TEXT("YASHASVI"), 95.2f, TEXT("Washim")}, 
    {43, TEXT("PRATHAMESH"), 80.4f, TEXT("Buldhana")}, 
    {44, TEXT("SUMIT"), 96.4f, TEXT("Wardha")}, 
    {45, TEXT("PRAJWAL"), 93.6f, TEXT("Chandrapur")}, 
    {46, TEXT("OM"), 67.5f, TEXT("Gondia")}, 
    {47, TEXT("SUVARNA"), 87.9f, TEXT("Bhandara")}, 
    {48, TEXT("SAKSHI"), 64.1f, TEXT("Dhule")}, 
    {49, TEXT("VIKRAM"), 90.2f, TEXT("Nandurbar")}, 
    {50, TEXT("BHAGWAN"), 57.2f, TEXT("Osmanabad")},
    {51, TEXT("MANGESH"), 66.7f, TEXT("Ratnagiri")}, 
    {52, TEXT("RAKESH"), 87.9f, TEXT("Raigad")}, 
    {53, TEXT("AARYA"), 77.1f, TEXT("Sindhudurga")}, 
    {54, TEXT("ONKAR"), 59.4f, TEXT("Sindhudurga")}, 
    {55, TEXT("RISHIKESH"), 63.8f, TEXT("Gadchiroli")}, 
    {56, TEXT("MALLIKARJUN"), 58.8f, TEXT("Akole")},
    {57, TEXT("REVAN"), 72.9f, TEXT("Akole")}, 
    {58, TEXT("MADHURI"), 81.1f, TEXT("Gadchiroli")}, 
    {59, TEXT("KARTIK"), 94.1f, TEXT("Sangli")}, 
    {60, TEXT("UTKARSH"), 97.4f, TEXT("Sangli")}, 
    {61, TEXT("VIVEK"), 89.3f, TEXT("Latur")}, 
    {62, TEXT("NISHA"), 17.7f, TEXT("Hingoli")}, 
    {63, TEXT("SHAHED"), 21.8f, TEXT("Hingoli")}, 
    {64, TEXT("MINAL"), 78.8f, TEXT("Parbhani")}, 
    {65, TEXT("PRATIK"), 99.8f, TEXT("Ahmednagar")}, 
    {66, TEXT("SAMADHAN"), 89.1f, TEXT("Ahmednagar")},
    {67, TEXT("YADNESH"), 82.2f, TEXT("Jalna")}, 
    {68, TEXT("YASHASVI"), 95.2f, TEXT("Washim")}, 
    {69, TEXT("PRATHAMESH"), 80.4f, TEXT("Buldhana")}, 
    {70, TEXT("SUMIT"), 96.4f, TEXT("Wardha")}, 
    {71, TEXT("PRAJWAL"), 93.6f, TEXT("Chandrapur")}, 
    {72, TEXT("OM"), 67.5f, TEXT("Gondia")}, 
    {73, TEXT("SUVARNA"), 87.9f, TEXT("Bhandara")}, 
    {74, TEXT("SAKSHI"), 64.1f, TEXT("Dhule")}, 
    {75, TEXT("VIKRAM"), 90.2f, TEXT("Nandurbar")}, 
}; 
