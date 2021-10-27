vector<long long> primes(100000);

void SieveofEratos(int n){
    primes[0]=5;primes[1]=5;
    for(int i =2; i*i <= n;i++){
        if(primes[i]==0){
            for(int j = i*i ; j<= n;j+= i){
                if(primes[j] == 0)
                    primes[j] = i;
            }
        }
    }
}
