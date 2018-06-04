#include <iostream>
#include <ctime>
#include <cmath>
void dvoich(int ch)
{
    int dch[7];
    int i = 0;
    while (ch>0)
    {
        dch[i] = ch % 2;
        ch = (ch - ch % 2) / 2;
        i++;
    }
    if (i<7) while (i<7) {
            dch[i] = 0;
            i++;
        }
    for (int f = 6; f >= 0; f--)
        printf("%d", dch[f]);
    printf("\n");
    i = 0;
}
double fun(int nch) {
    double ch;
    ch = (sin((double)nch))*(sin((double)nch)) + log((double)nch);

    return ch;
}
void main()
{
    setlocale(0, "");
    srand(time(NULL));
    int fu, N = 3, ms = 0;
    double f;
    double m = 0;
    const int H = 127;
    const int l = 7;
    for (int z = 1; z < 128; z++)
    {
        dvoich(z);
        printf("Значение приспособленности %lf\n", f = fun(z));
    }

    for (int g = 0; g<N; g++)
    {
        fu = rand() % 3;
        printf("Выбрали %d метод\n", fu+1);
        switch (fu)
        {
            case 0: {
                int maxs = 0, S, p[H];
                double pre, max = 0;
                for (int r = 0; r<H; r++) p[r] = rand() % 127 + 1;
                for (int r = 0; r<H; r++)
                {
                    S = p[r];
                    pre = fun(S);
                    if (max<pre)
                    {
                        max = pre;
                        maxs = S;
                    }

                    printf("Шаг %d\n", r + 1);
                    printf("Текущая кодировка\n");
                    dvoich(S);
                    printf("Ее приспособленность %lf\n", pre);
                    printf("Максимальная кодировка\n");
                    dvoich(maxs);
                    printf("значение максимума %lf\n\n\n\n", max);


                }
                if (max <= m) printf("\nnet\n");
                if (max>m)
                {
                    m = max;
                    ms = maxs;
                    printf("Максимальная кодировка\n");
                    dvoich(maxs);
                    printf("значение максимума %lf\n\n\n\n", max);
                }

                break; }
            case 1:
            {
                int S, maxS, okr[l], n = 10, x;
                double max, k;
                S = rand() % 127 + 1;
                max = fun(S);
                maxS = S;
                printf("Мы выбрали кодировку  ");
                dvoich(S);
                printf("Ее приспособленность(начальный максимум)%lf\n\n", max);
                okr[0] = S ^ 1;
                okr[1] = S ^ 2;
                okr[2] = S ^ 4;
                okr[3] = S ^ 8;
                okr[4] = S ^ 16;
                okr[5] = S ^ 32;
                okr[6] = S ^ 64;

                printf("Окрестность текущей кодировки\n");
                for (int c = 0; c<l; c++) dvoich(okr[c]);
                int z = l;//количество непроверенных кодировок из окрестности
                int d;//номер случайно выбранной кодировки из окрестности
                bool flag = false;
                for (int f = 0; f<n; f++)
                {
                    if (flag)
                    {
                        S = maxS;
                        printf("Теперь текущей стала кодировка ");
                        dvoich(S);
                        printf("\n");
                        okr[0] = S ^ 1;
                        okr[1] = S ^ 2;
                        okr[2] = S ^ 4;
                        okr[3] = S ^ 8;
                        okr[4] = S ^ 16;
                        okr[5] = S ^ 32;
                        okr[6] = S ^ 64;
                        printf("Окрестность текущей кодировки\n");
                        for (int c = 0; c<l; c++) dvoich(okr[c]);
                        z = l;
                        flag = false;
                    }

                    if (z>1) d = rand() % z; else d = 0;
                    printf("\nШаг номер %d, мы выбрали кодировку из окрестности:  ", f + 1);
                    dvoich(okr[d]);
                    printf("Ее приспособленность равна %lf\n", fun(okr[d]));
                    if (fun(okr[d])>max)
                    {
                        max = fun(okr[d]);
                        maxS = okr[d];
                        printf("Приспособленность этой кодировки больше максимума, зменяем максимум\n");
                        printf("Текущая максимальная кодировка");
                        dvoich(maxS);
                        printf("\nТекущий максимум %lf\n", max);
                        flag = true;
                        continue;

                    }
                    if (z == 1) {
                        f = n;
                        printf("В окрестности нет кодировки лучше , нашли оптимум:\n");
                    }

                    if (z>1) {
                        for (x = d; x<z - 1; x++) okr[x] = okr[x + 1];
                        okr[z - 1] = 0;
                        z--;
                        printf("Измененная окрестность\n");
                        for (int q = 0; q<z; q++) dvoich(okr[q]);
                    }


                    printf("Текущая максимальная кодировка");
                    dvoich(maxS);
                    printf("Текущий максимум %lf\n", max);

                }
                if (max <= m) printf("\nnet\n");
                if (max>m)
                {
                    m = max;
                    ms = maxS;
                    printf("НОВАЯ Максимальная кодировка\n");
                    dvoich(maxS);
                    printf("значение максимума %lf\n\n\n\n", max);
                }



                break;
            };
            case 2: {
                const int l = 7;
                int S, maxS, okr[l], n = 15, x, c, u, maxsok;
                double max, maxok;
                bool flag;
                S = rand() % 127 + 1;
                max = fun(S);
                maxS = S;
                printf("Мы выбрали кодировку  ");
                dvoich(S);
                printf("Ее приспособленность(начальный максимум)%lf\n\n", max);
                okr[0] = S ^ 1;
                okr[1] = S ^ 2;
                okr[2] = S ^ 4;
                okr[3] = S ^ 8;
                okr[4] = S ^ 16;
                okr[5] = S ^ 32;
                okr[6] = S ^ 64;
                printf("Окрестность текущей кодировки\n");
                for (int c = 0; c<l; c++) dvoich(okr[c]);
                for (int f = 0; f<n; f++)
                {

                    maxok = 0;
                    maxsok = 0;
                    for (u = 0; u<l; u++) if (fun(okr[u])>maxok) {
                            maxok = fun(okr[u]);
                            maxsok = okr[u];
                        }
                    flag = true;
                    if (maxok>max)
                    {
                        max = maxok;
                        maxS = maxsok;
                        S = maxS;
                        printf("текущей стала кодировка ");
                        dvoich(S);
                        printf("Текущий максимум %lf", max);
                        printf("\n");
                        okr[0] = S ^ 1;
                        okr[1] = S ^ 2;
                        okr[2] = S ^ 4;
                        okr[3] = S ^ 8;
                        okr[4] = S ^ 16;
                        okr[5] = S ^ 32;
                        okr[6] = S ^