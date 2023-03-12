#include <iostream>

using namespace std;

int main()
{
    int n, x, aux, sum, c, dim_secventa = 0, aux_dim_secv = 0, paritate_precedent = 0, max_dim_sec=0, st=1, dr=1, aux_st=1, aux_dr=1;
    cin >> n >> c;
    paritate_precedent = 0;
    for (int i=1; i<=n ; i++)
    {
        cin>>x;
        sum = 0;
        while (x>9)
        {
            sum = 0;
            while (x>0)
            {
                c=x%10;
                sum = sum + c;
                x=x/10;
            }
            x = sum;
        }


        //cifra control para
        if ((x%2) == 0)
        {
            // precedent nedefinit
            if (paritate_precedent == 0)
            {
                if (aux_dim_secv == 1)
                {
                    aux_st = i-1;
                }
                if (i==n)
                {
                    aux_dr = i;
                }
                aux_dim_secv++;
                paritate_precedent = 1;

            }

            //precedent par
            else if (paritate_precedent == 1)
            {

                dim_secventa = aux_dim_secv;
                aux_dim_secv = 1;
                paritate_precedent = 1;
                aux_dr = i-1;

            }

            // precedent impar
            else if (paritate_precedent == 2)
            {
                if (aux_dim_secv == 1)
                {
                    aux_st = i-1;
                }
                if (i==n)
                {
                    aux_dr = i;
                }
                aux_dim_secv++;
                paritate_precedent = 1;

            }
        }
        // cifra de contrl impara
        else
        {

            // precedent nedefinit
            if (paritate_precedent == 0)
            {
                if (aux_dim_secv == 1)
                {
                    aux_st = i-1;
                }
                if (i==n)
                {
                    aux_dr = i;
                }
                aux_dim_secv++;
                paritate_precedent = 2;

            }

            //precedent par
            else if (paritate_precedent == 1)
            {
                if (aux_dim_secv == 1)
                {
                    aux_st = i-1;
                }
                if (i==n)
                {
                    aux_dr = i;
                }
                aux_dim_secv++;
                paritate_precedent = 2;
            }

            // precedent impar
            else if (paritate_precedent == 2)
            {
                dim_secventa = aux_dim_secv;
                aux_dim_secv = 1;
                paritate_precedent = 2;
                aux_dr = i-1;
            }
        }

        if(dim_secventa>max_dim_sec)
        {
            max_dim_sec = dim_secventa;
            st = aux_st;
            dr = aux_dr;
        }

        if (i==n && aux_dim_secv>max_dim_sec)
        {
            max_dim_sec = aux_dim_secv;
            st = aux_st;
            dr = aux_dr;

        }
    }
    if (c == 1)
    {
        cout << max_dim_sec << endl;
    }
    else
    {
        cout << st << " " << dr << endl;
    }
    return 0;
}
