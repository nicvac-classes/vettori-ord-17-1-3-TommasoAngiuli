#include <iostream>
using namespace std;
int main() 
{
    int p, d, i, n, t, j, x, k, idx, inizio, fine, medio;
    cout << "quanti numeri generare?" << endl;
    cin >> n;
    int vp[n], vd[n], v3[n];
    bool scambio;
    p = 0;
    d = 0;
    i = 0;
    while (i <= n - 1) 
    {
        x = rand() % (n * 10);
        if (x % 2 == 0) 
        {
            vp[p] = x;
            p = p + 1;
        } 
        else 
        {
            vd[d] = x;
            d = d + 1;
        }
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= p - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= p - 2 - i) 
        {
            if (vp[j] > vp[j + 1]) 
            {
                t = vp[j];
                vp[j] = vp[j + 1];
                vp[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= d - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= d - 2 - i) 
        {
            if (vd[j] > vd[j + 1]) 
            {
                t = vd[j];
                vd[j] = vd[j + 1];
                vd[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    cout << "vettore numeri pari" << endl;
    while (i <= p - 1) 
    {
        cout << vp[i] << endl;
        i = i + 1;
    }
    i = 0;
    cout << "vettore numeri dispari" << endl;
    while (i <= d - 1) 
    {
        cout << vd[i] << endl;
        i = i + 1;
    }
    i = 0;
    j = 0;
    k = 0;
    while (i <= p - 1 && j <= d - 1) 
    {
        if (vp[i] <= vd[j]) 
        {
            v3[k] = vp[i];
            i = i + 1;
        } 
        else 
        {
            v3[k] = vd[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= p - 1) 
    {
        v3[k] = vp[i];
        k = k + 1;
        i = i + 1;
    }
    while (j <= d - 1) 
    {
        v3[k] = vd[j];
        k = k + 1;
        j = j + 1;
    }
    cout << "vettore 3" << endl;
    i = 0;
    while (i <= n - 1) 
    {
        cout << v3[i] << endl;
        i = i + 1;
    }
    cout << "inserisci il valore da cercare" << endl;
    cin >> x;
    p = 0;
    idx = (int) (-1);
    inizio = 0;
    fine = n - 1;
    while (inizio <= fine && idx == -1) 
    {
        medio = (int) (inizio + (double) (fine - inizio) / 2);
        p = p + 1;
        if (x == v3[medio]) 
        {
            idx = medio;
        } else 
        {
            p = p + 1;
            if (x > v3[medio]) 
            {
                inizio = medio + 1;
            } else 
            {
                fine = medio - 1;
            }
        }
    }
    cout << "il valore si trova nella cella " << idx << " e sono stati effettuati " << p << " passaggi con la ricerca binaria" << endl;
}