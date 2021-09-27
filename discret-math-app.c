/*=== LIBRARY ===*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<time.h>


/*=== GLOBAL VARIABLE ===*/
int i = 0;
char lanjut = 'n';
int pilih = 0, control = 0;
int kunci;
unsigned long long int biner = 0, desimal = 0, oktal = 0;
char heksa[100];
char nama[100], gender[20], irisan[100][20];
int gabungan[100];
int wel = 0;


/*=== PROCEDURE & FUNCTION DECLARE ===*/
void Clear();
void Select(int select);
void MenuUtama();
void Next();
void textcolor(unsigned short color);
void delay(float sec);
void WelcomeScreen();
void Contents();
/*--- Crypto ---*/
void Crypto();
void MenuCrypto();
void HelpCrypto();
void MenuCipher();
void MenuCaesar();
void Caesar();
void EnkripsiCaesar();
void DekripsiCaesar();
void InputCaesar(char kalimat[]);
void OutputCaesar(char kalimat[]);
void HelpCaesar();
void Vigenere();
void MenuVigenere();
void EnkripsiVigenere();
void DekripsiVigenere();
void InputVigenere(char kalimat[], char kunci[]);
void OutputVigenere(char kalimat[]);
void HelpVigenere();
/*--- FPB & KPK ---*/
void FPBKPK();
void HeaderFpb();
void HeaderKpk();
int ProsesFpb(int bil1, int bil2);
int ProsesKpk(int bil1, int bil2);
void BeginBack();
/*--- FAKTORIAL ---*/
void Fact();
void HeaderFact();
unsigned long long int ProsesFact(int n);
/*--- Convertion ---*/
void Convert();
void MenuConvert();
void DesBin();
void DesOkt();
void DesHeks();
void BinDes();
void BinOkt();
void BinHeks();
/*--- Set ---*/
void Himpunan();
void MenuHimpunan();
void Irisan();
void Gabungan();
void HelpHimpunan();
void Instruksi();


/*=== MAIN PROGRAM ===*/
int main(){
    i = 0;
    if (wel == 0){
        Clear();
        WelcomeScreen();
    }
    wel = 1;
    do
    {
        Clear();
        MenuUtama();
        //printf("             =======================================================\n\n");
        printf("             -------------------------------------------------------\n");
        printf("             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            FPBKPK();
            break;
        case 2:
            FPBKPK();
            break;
        case 3:
            Crypto();
            break;
        case 4:
            Fact();
            break;
        case 5:
            Convert();
            break;
        case 6:
            Himpunan();
            break;
        case 0:
            Contents();
            Next();
            break;
        default:
            main();
            break;
        }
        i++;
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
    return 0;
}

void textcolor(unsigned short color){
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}

/*=== PROCEDURE & FUNCTION DEFINE ===*/

//prosedur menu utama
void MenuUtama(){
    printf("\n\n");
    printf("                                  < MAIN MENU >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ===================== Select One` =====================\n");
    printf("             || 1. Least Common Multiple (LCM)                    ||\n");
    printf("             || 2. Greatest Common Divisor (GCD)                  ||\n");
    printf("             || 3. Cryptography                                   ||\n");
    printf("             || 4. Factorial                                      ||\n");
    printf("             || 5. Digital Number Convertion                      ||\n");
    printf("             || 6. Set                                            ||\n");
    printf("             || 0. CONTENTS <- Please read this first! %c%c         ||\n", 3, 3);
    printf("             =======================================================\n\n");
}

//prosedur membersihkan layar
void Clear(){
    if (i == 0 || ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y')))
    {
        system("cls");
        system("mode con cols=81 lines=40");
    }
}

//prosedur mengatur delay tampilan
void delay(float sec){
    float ms = 1000 * sec;
    clock_t start = clock();
    while (clock() < start + ms)
    ;
}

//prosedur welcome
void WelcomeScreen(){
    int i, j;
    char wait[] = "Please wait...";
    printf("\n\n");
    printf("             Enter your name : ");
    gets(nama);
    printf("             Enter your gender (male/female) : ");
    scanf("%s", gender);
    for ( i = 0; i <= 3; i++)
    {
        Clear();
        printf("\n\n");
        printf("             =======================================================\n");
        if (strcmp(gender, "female") == 0 || strcmp(gender, "Female") == 0 || strcmp(gender, "FEMALE") == 0)
        {
            printf("             %c Welcome! Mrs.%s! %c\n", 3, nama, 3);
            printf("             I hope you enjoy this program! %c\n", 2);
            printf("             =======================================================\n\n");
            if (i == 0) {
                delay(1);
                printf("             ");
                for ( j = 0; j < strlen(wait); j++)
                {
                    printf("%c", wait[j]);
                    delay(0.15);
                }
            }
            else
            {
                printf("             Please wait...");
            }
            printf("\n             Redirecting in %d\n", 3-i);
        }
        else if (strcmp(gender, "male") == 0 || strcmp(gender, "Male") == 0 || strcmp(gender, "MALE") == 0)
        {
            printf("             %c Welcome! Mr.%s! %c\n", 14, nama, 14);
            printf("             I hope you enjoy this program! %c\n", 2);
            printf("             =======================================================\n\n");
            if (i == 0) {
                delay(1);
                printf("             ");
                for ( j = 0; j < strlen(wait); j++)
                {
                    printf("%c", wait[j]);
                    delay(0.15);
                }
            }
            else
            {
                printf("             Please wait...");
            }
            printf("\n             Redirecting in %d\n", 3-i);
        }
        else
        {
            printf("             %c Welcome! %s! %c\n", 14, nama, 14);
            printf("             I hope you enjoy this program! %c\n", 2);
            printf("             =======================================================\n\n");
            if (i == 0) {
                delay(1);
                printf("             ");
                for ( j = 0; j < strlen(wait); j++)
                {
                    printf("%c", wait[j]);
                    delay(0.15);
                }
            }
            else
            {
                printf("             Please wait...");
            }
            printf("\n             Redirecting in %d\n", 3-i);
        }
        delay(1);
    }
}

//prosedur pengatur loop input
void Next(){
    printf("             -------------------------------------------------------\n");
    printf("             ===================== Next? (y/n) =====================\n");
    printf("                                 Your answer : ");
    scanf(" %c", &lanjut);
    while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'N' && lanjut != 'n')
    {
        printf("             -------------------------------------------------------\n");
        printf("             ===================== Next? (y/n) =====================\n");
        printf("                                Repeat answer : ");
        scanf(" %c", &lanjut);
    }
}

//prosedur pengatur mulai dan kembali
void BeginBack(){
    printf("             Enter 1 to begin..\n");
    printf("             Enter 0 to back..\n");
    printf("             ");
    scanf("%d", &control);
}

void Contents(){
    printf("\n             =======================================================\n");
    printf("            ( 1. Least Common Multiple (LCM)                        )\n");
    printf("            ( 2. Greatest Common Divisor (GCD)                      )\n");
    printf("            ( 3. Cryptography                                       )\n");
    printf("            (    3.1 Caesar Cipher                                  )\n");
    printf("            (    3.2 Vigenere Cipher                                )\n");
    printf("            ( 4. Factorial                                          )\n");
    printf("            ( 5. Digital Number Convertion                          )\n");
    printf("            (    5.1 Decimal to Binary                              )\n");
    printf("            (    5.2 Decimal to Octal                               )\n");
    printf("            (    5.3 Decimal to Hexadecimal                         )\n");
    printf("            (    5.4 Binary to Decimal                              )\n");
    printf("            (    5.5 Binary to Octal                                )\n");
    printf("            (    5.6 Binary to Hexadecimal                          )\n");
    printf("            ( 6. Set                                                )\n");
    printf("            (    6.1 Intersection                                   )\n");
    printf("            (    6.2 Union                                          )\n");
    printf("             =======================================================\n\n");
}

/*=== FPB & KPK ===*/
void FPBKPK(){
    i = 0;
    int bil1 = 0, bil2 = 0, hasil = 0;
    do
    {
        Clear();
        if (pilih == 1) HeaderKpk();
        if (pilih == 2) HeaderFpb();
        BeginBack();
        if (control == 1)
        {
            Clear();
            if (pilih == 1) HeaderKpk();
            if (pilih == 2) HeaderFpb();
            printf("             -------------------------------------------------------\n");
            printf("             Enter first number :\n");
            printf("             -> ");
            scanf("%d", &bil1);
            printf("             Enter second number :\n");
            printf("             -> ");
            scanf("%d", &bil2);
            if (pilih == 1) {
                hasil = ProsesKpk(bil1, bil2);
                printf("             The LCM of %d and %d is %d\n", bil1, bil2, hasil);
                
            }
            if (pilih == 2) {
                hasil = ProsesFpb(bil1, bil2);
                printf("             The GCD of %d and %d is %d\n", bil1, bil2, hasil);
            }
            Next();
        }
    } while ( control != 0 && (lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
    if (control == 0)
    {
        MenuUtama();
    }
}

void HeaderFpb(){
    printf("\n\n");
    printf("                           < GREATEST COMMON DIVISOR >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ================= `GCD Of Two Numbers =================\n");
}

int ProsesFpb(int bil1, int bil2){
    if (bil2 == 0)
    {
        return bil1;
    }
    else
    {
        int temp = bil1 % bil2;
        return ProsesFpb(bil2, temp);
    }
}

void HeaderKpk(){
    printf("\n\n");
    printf("                            < LEAST COMMON MULTIPLE >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ================= `LCM Of Two Numbers =================\n");
}

int ProsesKpk(int bil1, int bil2){
    int kpk = 0, fact = 1;
    kpk = (bil1 > bil2) ? bil1 : bil2;
    while (fact != 0)
    {
        if (kpk % bil1 == 0 && kpk % bil2 == 0)
        {
            return kpk;
            fact = 0;
        }
        kpk++;
    }
}


/*=== FAKTORIAL ===*/
void Fact(){
    i = 0;
    int bil = 0;
    unsigned long long int hasil = 0;
    do
    {
        Clear();
        HeaderFact();
        BeginBack();
        if (control == 1)
        {
            Clear();
            HeaderFact();
            printf("             -------------------------------------------------------\n");
            printf("             Enter number :\n");
            printf("             -> ");
            scanf("%d", &bil);
            hasil = ProsesFact(bil);
            printf("             %d factorial is %llu\n", bil, hasil);
            Next();
        }
    } while ( control != 0 && (lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
    if (control == 0)
    {
        MenuUtama();
    }
}

unsigned long long int ProsesFact(int n){
    if (n == 1)
        return 1;
    else
        return n * ProsesFact(n-1);
}

void HeaderFact(){
    printf("\n\n");
    printf("                                  < FACTORIAL >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ================= Factorial of Number =================\n");
}


/*=== CRYPTO ===*/
//prosedur utama cryto
void Crypto(){
    i = 0;
    do
    {
        Clear();
        MenuCrypto();
        printf("             -------------------------------------------------------\n");
        printf("             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            Caesar();
            break;
        case 2:
            Vigenere();
            break;
        case 0:
            HelpCrypto();
            Next();
            break;
        case 9:
            main();
            break;
        default:
            Crypto();
            break;
        }
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
}

//prosedur menu crypto
void MenuCrypto(){
    printf("\n\n");
    printf("                                < -CRYPTOGRAPHY >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             =================== Select A Cipher ===================\n");
    printf("             || 1. Caesar Cipher                                  ||\n");
    printf("             || 2. Vigenere Cipher                                ||\n");
    printf("             || 9. BACK                                           ||\n");
    printf("             || 0. HELP                                           ||\n");
    printf("             =======================================================\n\n");
}

//prosedur help crypto
void HelpCrypto(){
    //system("mode con cols=81 lines=50");
    printf("\n             =======================================================\n");
    printf("            (    Kriptografi merupakan salah satu cabang dari ilmu  )\n");
    printf("            ( kriptologi. Dimana kriptografi ini merupakan sebuah   )\n");
    printf("            ( ilmu yang mempelajari teknik-teknik matematika yang   )\n");
    printf("            ( berhubungan dengan aspek keamanan informasi seperti   )\n");
    printf("            ( kerahasiaan, integritas data, serta otentikasi.       )\n");
    printf("            ( (Menez, 1996)                                         )\n");
    printf("            (    Program ini membantu melakukan proses enkripsi dan )\n");
    printf("            ( dekripsi pesan menggunakan cipher (algoritma) yang    )\n");
    printf("            ( telah disediakan.                                     )\n");
    printf("            (    Anda dapat menentukan pesan yang ingin di enkripsi )\n");
    printf("            ( dan di dekripsi serta kunci yang diinginkan. Pesan yg )\n");
    printf("            ( dimaksud dapat berupa kata/kalimat, sedangkan kunci   )\n");
    printf("            ( berbeda-beda spesifikasinya di setiap cipher.         )\n");
    printf("             =======================================================\n\n");
}

//prosedur menu cipher
void MenuCipher(){
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ===================== Select One` =====================\n");
    printf("             || 1. Encryption                                     ||\n");
    printf("             || 2. Decryption                                     ||\n");
    printf("             || 9. BACK                                           ||\n");
    printf("             || 0. HELP                                           ||\n");
    printf("             =======================================================\n\n");
}

/*=== CAESAR CIPHER ===*/
void MenuCaesar(){
    i = 0;
    printf("\n\n");
    printf("                                < CAESAR CIPHER >\n");
    MenuCipher();
}

void Caesar(){
    i = 0;
    do
    {
        Clear();
        MenuCaesar();
        printf("             =======================================================\n");
        printf("             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            printf("             -------------------------------------------------------\n");
            EnkripsiCaesar();
            Next();
            break;
        case 2:
            printf("             -------------------------------------------------------\n");
            DekripsiCaesar();
            Next();
            break;
        case 0:
            HelpCaesar();
            Next();
            break;
        case 9:
            Crypto();
            break;
        default:
            Caesar();
            break;
        }
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
}

void EnkripsiCaesar(){
    char kalimat[1000];
    InputCaesar(kalimat);
    kunci %= 26;
    for (int i = 0; i < strlen(kalimat); i++)
    {
        if (kunci >= 0)
        {
            if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
            {
                if (kalimat[i] + kunci > 122)
                {
                    kalimat[i] = (kalimat[i] + kunci) - 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] + kunci;
                }
            }
            else if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
            {
                if (kalimat[i] + kunci > 90)
                {
                    kalimat[i] = (kalimat[i] + kunci) - 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] + kunci;
                }
            }
        }
        else if (kunci < 0)
        {
            if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
            {
                if (kalimat[i] + kunci < 97)
                {
                    kalimat[i] = (kalimat[i] + kunci) + 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] + kunci;
                }
            }
            else if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
            {
                if (kalimat[i] + kunci < 65)
                {
                    kalimat[i] = (kalimat[i] + kunci) + 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] + kunci;
                }
            }
        }
    }
    printf("             The ciphertext :\n");
    OutputCaesar(kalimat);
}

void DekripsiCaesar(){
    char kalimat[1000];
    InputCaesar(kalimat);
    kunci = kunci % 26;
    for (int i = 0; i < strlen(kalimat); i++)
    {
        if (kunci >= 0)
        {
            if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
            {
                if (kalimat[i] - kunci < 97)
                {
                    kalimat[i] = (kalimat[i] - kunci) + 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] - kunci;
                }
            }
            else if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
            {
                if (kalimat[i] - kunci < 65)
                {
                    kalimat[i] = (kalimat[i] - kunci) + 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] - kunci;
                }
            }
        }
        else if (kunci < 0)
        {
            if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
            {
                if (kalimat[i] - kunci > 122)
                {
                    kalimat[i] = (kalimat[i] - kunci) - 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] - kunci;
                }
            }
            else if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
            {
                if (kalimat[i] - kunci > 90)
                {
                    kalimat[i] = (kalimat[i] - kunci) - 26;
                }
                else
                {
                    kalimat[i] = kalimat[i] - kunci;
                }
            }
        }
    }
    printf("             The ciphertext :\n");
    OutputCaesar(kalimat);
}

void InputCaesar(char kalimat[]){
    if (pilih == 1)
    {
        printf("             Enter plaintext without space:\n");
    }
    else if (pilih == 2)
    {
        printf("             Enter ciphertext without space:\n");
    }
    printf("             -> ");
    scanf("%s", kalimat);
    printf("             Enter the key (a number) : \n");
    printf("             -> ");
    scanf("%d", &kunci);
}

void OutputCaesar(char kalimat[]){
    int i, j;
    printf("             -> ");
    i = 0;
    if (pilih == 1)
    {
        while (i < strlen(kalimat))
        {
            for ( j = 0; j < 4; j++)
            {
                printf("%c", kalimat[i]);
                i++;
                if(i == strlen(kalimat))
                {
                    break;
                }
            }
            printf(" ");
        }    
    }
    else if (pilih == 2)
    {
        printf("%s", kalimat);
    }
    printf("\n");
}

void HelpCaesar(){
    printf("\n             =======================================================\n");
    printf("            (    Chiper Caesar merupakan sebuah algoritma klasik.   )\n");
    printf("            ( Menggunakan metode substitusi mono-alfabet, yaitu de- )\n");
    printf("            ( ngan menggeser huruf alfabet sesuai dengan kunci yang )\n");
    printf("            ( dimasukkan.                                           )\n");
    printf("            (    Kunci dalam cipher ini berupa angka. Kunci positif )\n");
    printf("            ( akan memajukan posisi huruf sesuai kunci, sedangkan   )\n");
    printf("            ( negatif akan berlaku sebaliknya (memundurkan huruf).  )\n");
    printf("            (    Plainteks yang dimasukkan adalah 26 huruf alfabet  )\n");
    printf("            ( tanpa spasi, tanda baca, maupun karakter.             )\n");
    printf("             =======================================================\n\n");
}

/*=== VIGENERE CIPHER ===*/
void Vigenere(){
    i = 0;
    do
    {
        Clear();
        MenuVigenere();
        printf("             =======================================================\n");
        printf("             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            printf("             -------------------------------------------------------\n");
            EnkripsiVigenere();
            Next();
            break;
        case 2:
            printf("             -------------------------------------------------------\n");
            DekripsiVigenere();
            Next();
            break;
        case 0:
            HelpVigenere();
            Next();
            break;
        case 9:
            Crypto();
            break;
        default:
            Vigenere();
            break;
        }
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
}

void MenuVigenere(){
    i = 0;
    printf("\n\n");
    printf("                               < VIGENERE CIPHER >\n");
    MenuCipher();
}

void EnkripsiVigenere(){
    char kalimat[1000];
    char kunci[1000], kunci2[1000];
    InputVigenere(kalimat, kunci);
    int panjang = strlen(kunci);
    i = 0;
    int j;
    while (i < strlen(kalimat))
    {
        for ( j = 0; j < panjang; j++)
        {
            kunci2[i] = kunci[j] - 97;
            i++;
            if (i == strlen(kalimat))
            {
                break;
            }
        }
    }
    kunci2[i] = '\0';
    for ( i = 0; i < strlen(kalimat); i++)
    {
        kunci2[i] = kunci2[i] % 26;
        if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
        {
            kalimat[i] = kalimat[i] - 32;
        }
        if (kalimat[i] + kunci2[i] > 90)
        {
            kalimat[i] = (kalimat[i] + kunci2[i]) - 26;
        }
        else
        {
            kalimat[i] = kalimat[i] + kunci2[i];
        }
    }
    printf("             The ciphertext :\n");
    OutputVigenere(kalimat);
}

void DekripsiVigenere(){
    char kalimat[1000];
    char kunci[1000], kunci2[1000];
    InputVigenere(kalimat, kunci);
    int panjang = strlen(kunci);
    i = 0;
    int j;
    while (i < strlen(kalimat))
    {
        for ( j = 0; j < panjang; j++)
        {
            kunci2[i] = kunci[j] - 97;
            i++;
            if (i == strlen(kalimat))
            {
                break;
            }
        }
    }
    kunci2[i] = '\0';
    for ( i = 0; i < strlen(kalimat); i++)
    {
        kunci2[i] = kunci2[i] % 26;
        if (kalimat[i] - kunci2[i] < 65)
        {
            kalimat[i] = (kalimat[i] - kunci2[i]) + 26;
        }
        else
        {
            kalimat[i] = kalimat[i] - kunci2[i];
        }
    }
    printf("             The ciphertext :\n");
    OutputVigenere(kalimat);
}

void InputVigenere(char kalimat[], char kunci[]){
    if (pilih == 1)
    {
        printf("             Enter plaintext without space:\n");
    }
    else if (pilih == 2)
    {
        printf("             Enter ciphertext without space:\n");
    }
    printf("             -> ");
    scanf("%s", kalimat);
    printf("             Enter the key (a word) : \n");
    printf("             -> ");
    scanf("%s", kunci);
}

void OutputVigenere(char kalimat[]){
    int i, j;
    printf("             -> ");
    i = 0;
    if (pilih == 1)
    {
        while (i < strlen(kalimat))
        {
            for ( j = 0; j < 4; j++)
            {
                printf("%c", kalimat[i]);
                i++;
                if(i == strlen(kalimat))
                {
                    break;
                }
            }
            printf(" ");
        }    
    }
    else if (pilih == 2)
    {
        printf("%s", kalimat);
    }
    printf("\n");
}

void HelpVigenere(){
    printf("\n             =======================================================\n");
    printf("            (    Chiper Vigenere, yaitu salah satu cipher klasik yg )\n");
    printf("            ( menggunakan metode substitusi poli-alfabet dan merupa-)\n");
    printf("            ( kan cipher abjad-majemuk.                             )\n");
    printf("            (    Kuncinya berupa sebuah kata yang setiap hurufnya   )\n");
    printf("            ( adalah kunci untuk melakukan enkripsi plainteks.      )\n");
    printf("            (    Plainteks yang dimasukkan adalah 26 huruf alfabet  )\n");
    printf("            ( tanpa spasi, tanda baca, maupun karakter.             )\n");
    printf("             =======================================================\n\n");
}

/*=== Konversi Bilangan ===*/
void Convert(){
    i = 0;
    do
    {
        Clear();
        MenuConvert();
        printf("             -------------------------------------------------------\n");
        printf("             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            DesBin();
            printf("\n");
            Next();
            break;
        case 2:
            DesOkt();
            printf("\n");
            Next();
            break;
        case 3:
            DesHeks();
            printf("\n");
            Next();
            break;
        case 4:
            BinDes();
            printf("\n");
            Next();
            break;
        case 5:
            BinOkt();
            printf("\n");
            Next();
            break;
        case 6:
            BinHeks();
            printf("\n");
            Next();
            break;
        case 9:
            main();
            break;
        default:
            Convert();
            break;
        }
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
}

void MenuConvert(){
    //printf("             =======================================================\n\n");
    printf("\n\n                                  < CONVERTER >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n");
    printf("                              </ `Digital Number />\n\n");
    printf("             ====================  Select One` =====================\n");
    printf("             || 1. Decimal -> Binary                              ||\n");
    printf("             || 2. Decimal -> Octal                               ||\n");
    printf("             || 3. Decimal -> Hexadecimal                         ||\n");
    printf("             || 4. Binary -> Decimal                              ||\n");
    printf("             || 5. Binary -> Octal                                ||\n");
    printf("             || 6. Binary -> Hexadecimal                          ||\n");
    printf("             || 9. BACK                                           ||\n");
    printf("             =======================================================\n\n");
}

void DesBin(){
    int i = 0, j = 0;
    int arrBin[200] = {0};
    int binary[200] = {0};
    printf("             -> Insert decimal number : ");
    scanf("%llu", &desimal);
    while (desimal != 0)
    {
        arrBin[i] = desimal%2;
        desimal /= 2;
        i++;
    }
    printf("             -> The binary number is : ");
    while (j < i)
    {
        binary[j] = arrBin[i-(j+1)];
        printf("%llu", binary[j]);
        j++;
    }
    i = 0;
    while (i < j)
    {
        arrBin[i] = 0;
        binary[i] = 0;
        i++;
    }
    i = 0;
    j = 0;
}

void DesOkt(){
    int i = 0, j = 0;
    unsigned long long int rem, help = 1;
    printf("             -> Insert decimal number : ");
    scanf("%llu", &desimal);
    while (desimal != 0)
    {
        rem = desimal % 8;
        oktal = rem * help + oktal;
        help *= 10;
        desimal /= 8;
    }
    printf("             -> The octal number is : %llu", oktal);
    oktal = 0;
}

void DesHeks(){
    int i = 0, j = 0;
    unsigned long long int rem;
    char tampung[100];
    printf("             -> Insert decimal number : ");
    scanf("%llu", &desimal);
    while (desimal != 0)
    {
        rem = desimal % 16;
        if (rem>9)
            tampung[i]=(char)(rem+55);
        else
            tampung[i]=(char)(rem+48);
        desimal /= 16;
        i++;
    }
    while (j < i)
    {
        heksa[j] = tampung[i-(j+1)];
        j++;
    }
    heksa[j] = '\0';
    printf("             -> The hexadecimal number is : %s", heksa);
    i = 0;
    j = 0;
}

void BinDes(){
    unsigned long long int pangkat = 1, getbin = 0;
    printf("             -> Insert binary number : ");
    scanf("%llu", &biner);
    while (biner!=0)
    {
        getbin=biner%10;
        desimal=getbin*pangkat+desimal;
        biner=biner/10;
        pangkat=pangkat*2;
    }
    printf("             -> The decimal number is : %llu", desimal);
    desimal = 0;
}

void BinOkt(){
    unsigned long long int pangkat = 1, getbin = 0;
    printf("             -> Insert binary number : ");
    scanf("%llu", &biner);
    while (biner!=0)
    {
        getbin=biner%10;
        desimal=getbin*pangkat+desimal;
        biner=biner/10;
        pangkat=pangkat*2;
    }
    int rem, help = 1;
    while (desimal != 0)
    {
        rem = desimal % 8;
        oktal = rem * help + oktal;
        help *= 10;
        desimal /= 8;
    }
    printf("             -> The octal number is : %llu", oktal);
    oktal = 0;
}

void BinHeks(){
    int i = 0, j = 0;
    unsigned long long int pangkat = 1, getbin = 0;
    printf("             -> Insert binary number : ");
    scanf("%llu", &biner);
    while (biner!=0)
    {
        getbin=biner%10;
        desimal=getbin*pangkat+desimal;
        biner=biner/10;
        pangkat=pangkat*2;
    }
    unsigned long long int rem;
    char tampung[100];
    while (desimal != 0)
    {
        rem = desimal % 16;
        if (rem>9)
            tampung[i]=(char)(rem+55);
        else
            tampung[i]=(char)(rem+48);
        desimal /= 16;
        i++;
    }
    while (j < i)
    {
        heksa[j] = tampung[i-(j+1)];
        j++;
    }
    heksa[j] = '\0';
    printf("             -> The hexadecimal number is : %s", heksa);
    i = 0;
    j = 0;
}

void Himpunan(){
    i = 0;
    do
    {
        Clear();
        MenuHimpunan();
        Instruksi();
        printf("             -------------------------------------------------------\n");
        printf("\n             Enter your choice : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            Irisan();
            Next();
            break;
        case 2:
            Gabungan();
            Next();
            break;
        case 9:
            main();
            break;
        default:
            Himpunan();
            break;
        }
    } while ((lanjut != 'n' || lanjut != 'N') && (lanjut == 'y' || lanjut == 'Y'));
}

void MenuHimpunan(){
    i = 0;
    printf("\n\n");
    printf("                                     < SET >\n");
    printf("                         </ By : Sekar M.K. [2007703] />\n\n");
    printf("             ===================== Select One` =====================\n");
    printf("             || 1. Intersection                                   ||\n");
    printf("             || 2. Union                                          ||\n");
    printf("             || 9. BACK                                           ||\n");
    printf("             =======================================================\n\n");
}

void Irisan(){
    int jml1 = 0, jml2 = 0;
    char set1[100][20], set2[100][20];
    int i, j, idx = 0;
    i = 0;
    printf("             Enter set A : \n");
    printf("             -> ");
    do
    {
        scanf("%s", &set1[i]);
        jml1++;
        i++;
    } while (strcmp(set1[i-1], ";") != 0);
    i = 0;
    printf("             Enter set B : \n");
    printf("             -> ");
    do
    {
        scanf("%s", &set2[i]);
        jml2++;
        i++;
    } while (strcmp(set2[i-1], ";") != 0);
    printf("             The intersection is : \n");
    printf("             -> ");
    for ( i = 0; i < jml1-1; i++)
    {
        for ( j = 0; j < jml2-1; j++)
        {
            if (strcmp(set1[i], set2[j]) == 0)
            {
                strcpy(irisan[idx], set2[j]);
                printf("%s", irisan[idx]);
                if(j != jml2-2)
                    printf(" ");
                idx++;
            }
        }
    }
    printf("\n\n");
}

void Gabungan(){
    int i, j, idx = 0, jml1 = 0, jml2 = 0, rem = 1, temp = 0;
    char set1[100][10], set2[100][10];
    i = 0;
    printf("             Enter set A : \n");
    printf("             -> ");
    do
    {
        scanf("%s", &set1[i]);
        if (strcmp(set1[i], ";") != 0)
        {
            for ( j = strlen(set1[i])-1; j >= 0; j--)
            {
                set1[i][j] = ((set1[i][j] - '0') * rem);
                temp += set1[i][j];
                rem *= 10;
            }
            gabungan[idx] = temp;
        }
        idx++;
        i++;
        rem = 1; temp = 0;
    } while (strcmp(set1[i-1], ";") != 0);
    rem = 1; temp = 0;
    int saveidx = idx - 1, sama = 0;
    i = 0; idx -= 1;
    printf("             Enter set B : \n");
    printf("             -> ");
    do
    {
        scanf("%s", &set2[i]);
        if (strcmp(set2[i], ";") != 0)
        {
            for ( j = strlen(set2[i])-1; j >= 0; j--)
            {
                set2[i][j] = ((set2[i][j] - '0') * rem);
                temp += set2[i][j];
                rem *= 10;
            }
            for ( j = 0; j < saveidx; j++)
            {
                if (temp == gabungan[j])
                {
                    sama = 1;
                }
            }
            if (sama != 1) gabungan[idx] = temp;
        }
        if (sama != 1) idx++;
        i++;
        rem = 1; temp = 0;
        sama = 0;
    } while (strcmp(set2[i-1], ";") != 0);
    printf("             The union is : \n");
    printf("             -> ");
    int min = 0, idxMin = 0;
    for ( i = 0; i < idx-1; i++)
    {
        idxMin = i;
        for ( j = i+1; j < idx-1; j++)
        {
            if (gabungan[j] < gabungan[idxMin])
            {
                idxMin = j;
            }
        }
        min = gabungan[idxMin];
        gabungan[idxMin] = gabungan[i];
        gabungan[i] = min;
        printf("%d", gabungan[i]);
        if (i != idx-2)
        {
            printf(" ");
        }
    }
    printf("\n\n");
}

void Instruksi(){
    printf("             -------------------------------------------------------\n");
    printf("                              `Please read this %c%c%c\n", 2, 2, 2);
    printf("             Input the members of set one by one.\n");
    printf("             Separate member to member with space.\n");
    printf("             Ends the input of set with a space and semicolon ( ;).\n");
    printf("             Example input :\n");
    printf("             -> 1 2 3 4 5 ;\n");
    printf("             Then, press enter to input members of the next set.\n");
}
