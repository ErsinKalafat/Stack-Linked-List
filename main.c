#include <stdio.h>
#include <stdlib.h>

struct YiginDugumu
{
    int eleman;
    struct YiginDugumu * sonraki;
};

int ekle(int eleman);
int al();
int ust();

struct YiginDugumu * yigin_ilk = NULL;

int ekle(int eleman)
{
    struct YiginDugumu * yeni = (struct YiginDugumu*)malloc(sizeof(struct YiginDugumu));
    yeni->eleman = eleman;

    if (yigin_ilk == NULL)
    {
        yeni->sonraki = NULL;
        yigin_ilk = yeni;
    }
    else
    {
        yeni->sonraki = yigin_ilk;
        yigin_ilk = yeni;
    }

    return 0;
}

int al()
{
    if (yigin_ilk == NULL)
    {
        printf("HATA: yiginda eleman yok\n");
        exit(1);
    }

    struct YiginDugumu * silinecek = yigin_ilk;
    yigin_ilk = yigin_ilk->sonraki;

    int eleman = silinecek->eleman;
    free(silinecek);

    return eleman;
}

int ust()
{
    return yigin_ilk->eleman;
}

int main()
{
    ekle(1);
    ekle(2);
    ekle(5);

    printf("%d\n", al());
    printf("%d\n", al());
    printf("%d\n", al());

    return 0;
}
