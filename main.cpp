#include <iostream>
using namespace std;
class CDate{
private:
    int Ngay,Thang,Nam;
public:
    CDate(int Day, int Month, int Year){
        Ngay = Day;
        Thang = Month;
        Nam = Year;
    }
    bool CheckDuLieu(int& Day, int& Month, int& Year){
        switch (Month){
        case 1:case 3:case 5: case 7: case 8: case 10: case 12:
            return (Day > 0 && Day <= 31);
        case 4: case 6: case 9: case 11:
            return (Day > 0 && Day <= 30);
        case 2:
            if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0)) return (Day > 0 && Day <= 29);
            else return (Day > 0 && Day <= 28);
        default:
            return false;
        }
    }
    friend istream& operator >> (istream& In, CDate& DuLieu){
        bool KiemTra;
            do{
            KiemTra = false;
            cout << "Nhap du lieu ngay: ";
            In >> DuLieu.Ngay;
            cout << "Nhap du lieu thang: ";
            In >> DuLieu.Thang;
            cout << "Nhap du lieu nam: ";
            In >> DuLieu.Nam;
            KiemTra = DuLieu.CheckDuLieu(DuLieu.Ngay, DuLieu.Thang, DuLieu.Nam);
            if (KiemTra == false)
            cout << "Du lieu nhap vao khong hop le. Vui long nhap lai" << endl;
            } while (!KiemTra);
        return In;
    }
    friend ostream& operator << (ostream& Out,const CDate& DuLieu){
        Out << "Ngay " << DuLieu.Ngay << " thang " << DuLieu.Thang << " nam " << DuLieu.Nam;
        return Out;
    }
    CDate operator+(int& DuLieu){
        CDate Date = *this;
        int Temp = Date.Ngay + DuLieu;
        int thang[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((Date.Nam % 4 == 0 && Date.Nam % 100 != 0) || (Date.Nam % 400 == 0))
        thang[1] = 29;
        do{
            switch (Date.Thang){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                Temp > 31 ? (Date.Thang++, Temp -= 31) : (Date.Ngay = Temp, Temp = 0);
            break;
            case 4: case 6: case 9: case 11:
                Temp > 30 ? (Date.Thang++, Temp -= 30) : (Date.Ngay = Temp, Temp = 0);
                break;
            case 2:
                if ((Date.Nam % 4 == 0 && Date.Nam % 100 != 0) || (Date.Nam % 400 == 0))
                    Temp > 29 ? (Date.Thang++, Temp -= 29) : (Date.Ngay = Temp, Temp = 0);
                else
                    Temp > 28 ? (Date.Thang++, Temp -= 28) : (Date.Ngay = Temp, Temp = 0);
                break;
            }
        } while (Temp > 0);
        return Date;
    }
    CDate operator-(int& DuLieu){
        CDate Date = *this;
        int Temp = DuLieu;
        do{
            if (Date.Ngay > Temp){
                Date.Ngay -= Temp;
                Temp = 0;
            }
            else{
                Temp -= Date.Ngay;
                Date.Thang--;
                switch (Date.Thang){
                case 1: case 3: case 5: case 7: case 8: case 10:
                    Date.Ngay = 31;
                    break;
                case 0:
                    Date.Thang = 12;
                    Date.Nam--;
                case 4: case 6: case 9: case 11:
                    Date.Ngay = 30;
                    break;
                case 2:
                    if ((Date.Nam % 4 == 0 && Date.Nam % 100 != 0) || (Date.Nam % 400 == 0))
                        Date.Ngay = 29;
                    else
                        Date.Ngay = 28;
                    break;
                }
            }
        } while (Temp > 0);
        return Date;
    }
};
int main()
{
    CDate a(0,0,0);
    cout<<"Nhap ngay thang nam: \n";
    cin>>a;
    cout<<"Ngay thang nam vua nhap: ";
    cout<<a<<endl;
    cout<<"Nhap n: ";
    int n;
    cin>>n;
    cout<<"Sau khi them vao "<<n<<" ngay: ";
    cout<<a+n<<endl;
    cout<<"Sau khi bot di "<<n<<" ngay: ";
    cout<<a-n;
}
