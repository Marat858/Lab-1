#include <iostream> 
using namespace std;
int main()
{
    setlocale(0, "");
    /*1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без:
    int, short int, long int, float, double, long double, char и bool.*/
    cout << "Тип данных int - " << sizeof(int) << " байта" << endl;
    cout << "Тип данных short int - " << sizeof(short int) << " байта" << endl;
    cout << "Тип данных long int - " << sizeof(long int) << " байта" << endl;
    cout << "Тип данных float - " << sizeof(float) << " байта" << endl;
    cout << "Тип данных double - " << sizeof(double) << " байта" << endl;
    cout << "Тип данных long double - " << sizeof(long double) << " байт" << endl;
    cout << "Тип данных char - " << sizeof(char) << " байт" << endl;
    cout << "Тип данных bool - " << sizeof(bool) << " байт" << endl << endl;



    //2
    int e;
    cin >> e;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    for (int i = 0; i <= sizeof(int) * 8 - 1; i++)
    {
        putchar(mask & e ? '1' : '0');
        mask >>= 1;
        if ((i + 1) % 8 == 0 || i == 0)
            cout << ' ';
    }
    cout << endl;
    e = e << 1;
    cout << e << endl;
    //3
    union {
        float f; //0101
        int tool;  //0101
    };
    cin >> f;
    mask = 1 << (sizeof(float) * 8 - 1); //Сдвигаем на все биты влево
    for (int i = 0; i <= sizeof(int) * 8 - 1; i++)
    {
        putchar(mask & tool ? '1' : '0');
        mask >>= 1;
        if (i == 0 || i == 8)
            cout << ' ';
    }
    cout << endl;
    tool = tool << 1;
    cout << f << endl;

  
    
    //4
    union {
        double d;
        int masd[2];
    };
    cin >> d;
    mask = 1 << sizeof(int) * 8 - 1;
    for (int j = 0; j <= sizeof(int) * 8 - 1; j++)
    {
        putchar(masd[1] & mask ? '1' : '0');
        mask >>= 1;
        if (j == 0 || j == 11)
            cout << " ";

    }
    mask = 1 << sizeof(int) * 8 - 1;
    for (int j = 0; j <= sizeof(int) * 8 - 1; j++)
    {
        putchar(masd[0] & mask ? '1' : '0');
        mask >>= 1;
        
    }
    if (mask & masd[1]) {
        // плохой случай
        masd[0] = masd[0] << 1;
        masd[1] = masd[1] << 1;
        masd[0]++;
    }
    else {
        // хороший случай
        masd[0] = masd[0] << 1;
        masd[1] = masd[1] << 1;
    }
    // 11001010 00101011
    // 10010100 01010110 хороший случай

    // 11001011 10101011
    // 10010110 01010110 плохой случай

    // 11001010 10101011
    // 10010100 01010110 плохой случай

    // 11001011 01101011
    // 10010110 11010110 хороший  случай
    cout << endl;
    cout << d << endl;
    return 0;
}
/*for (int j = 0; j <= sizeof(int) * 8 - 1; j++)
{
    putchar(masd[i] & mask ? '1' : '0');
    mask >>= 1;
    if (i == 1 && (j == 0 || j == 11))
        cout << ' ';
}*/

