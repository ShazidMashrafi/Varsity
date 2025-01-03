
            if (k == n && !all_placed)
            {
                // for (int j = 1; j <= n; j++)
                // {
                    
                //     cout << x[j] << " ";
                // }
                //cout << endl;
                Display(n);
                all_placed = 1;
                return true;
            }
            NQueens(k + 1, n);