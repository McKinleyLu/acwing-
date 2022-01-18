for(int s = 0 ; s*w[i] <= m ; s++){
                f[i][j] = max(f[i][j],f[i-1][j - s*w[i]] + value[i]*k);
             }
         }