/*
    Primality Test(Miller-Rabin) :-
    -----------------------------
    -WE can use this test to check if a number that is in the range [1-10^18] is prime or not.

    Explanation :-
    -------------

    -So we want to check if the given number which is in range 1-10^18 is prime or not, here we cannot make the prime sieve array as the constraints are very large.
    -So we will have to use some theorems and other techniques to check if it is a prime or not.
     ________________________________________________________________________________________________________________
    |*Theorems which will be used -                                                                                  |
    |1)Fermat's little theorem(FMT) -                                                                                     |
    |    a^p ≡ a(mod p)                           (here p is a prime number)                                         |
    |    which can be written as,                                                                                    |   
    |    (a^p)%p = a                                                                                                 |
    |    (a^(p-1))%p = 1                                                                                             |
    |                                                                                                                |
    |2)Euclid's Lemma -                                                                                              |
    |    if p completely divides a*b and p is a prime number, then p must completely divide either a or b, or both.  |
    |________________________________________________________________________________________________________________|
        
    -now there are some base cases i.e 1 is not prime, 2 is prime and any even number>2 is not prime.

    -So we know that n will be odd and >=3 for it to be a prime number.

    -as n is odd, so n-1 will be even....we can write n-1 as -> n-1=d*(2^s)     [d=odd number]
                                                                
    -Now by FMT, if (a^d)%n==1...then we can say that n can be a prime number.(and this is true bcz d is a factor of n-1 and also d is odd.)
    
    -Now a^(n-1) can be written as -> a^(d*2^s)
    -Now suppose s=10, then all the number we have is -> a^(d*2^0),a^(d*2^1)....a^(d*2^10)
    as we have already checked for a^(d*2^0), so we will check for all other numbers.
    -If you notice then we can represent all these numbers(a^(d*2^0),a^(d*2^1)....a^(d*2^10)) as x^2,
    ex:  if s=5, then we can write the term as (a^((d*2^4))^2, so here x=a^((d*2^4).
    -Now why we are doing this is bcz, bcz of FLT if n is prime then-
        (x^2)%n = 1     (as n-1 = d*(2^s))
        Factorize it -
        ((x+1)(x-1))%n=1

        Now due to euclid's lemma- 
        Either (x+1)%n=0 or (x-1)%n=0    (bcz we are assuming n to be a prime here)
        This gives us x%n = -1≡n-1(here -1 represents n-1) or x%n = 1

    -So we will check for x in [0-s-1], as in the example our last term was a^(d*(2^10)),
     which when represents as x^2 will be (a^(d*(2^9)))^2...So our last s is s-1.

    -Now for a, we can randomly choose a and check all these conditions, but instead of choosing a randomly we will just take the first 9 primes one by one and check all those conditions on them.
    
*/

#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mod 1000000007
using namespace std;
 
//used to a*b
ll modular_multiplication(ll a,ll b,ll m){
    ll res=0;
    while(b){
        if(b&1ll){
            res+=a;
        }
        a*=2;
        b>>=1;
        res%=m;
        a%=m;
    }
    return res;
}

//used to a^d
ll modular_exponentiation(ll a,ll d,ll m){
    ll res=1;
    while(d){
        if(d&1ll){
            // res*=a;
            res=modular_multiplication(res,a,m);
        }
        a=modular_multiplication(a,a,m);
        a%=m;
        d>>=1;
    }
    return res;
}


bool miller_rabin(ll n){
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;

    //now as n is odd, so n-1 will be even.
    ll d=n-1,s=0;
    while(d%2==0){
        s++;
        d/=2;
    }

    // n-1 = d*(2^s)   , here d is an odd number.

    vector<ll> a({2,3,5,7,11,13,17,19,23});

    f(i,0,a.size()){
        if(a[i]>n-2) continue;  //as a lies in range [2,n-2]
        //check if (a^d)%n==1, calculate a^d using modular exponentiation
        ll ad=modular_exponentiation(a[i],d,n);
        if(ad%n==1) continue;
        bool prime=false;
        f(j,0,s){
            ll tr=modular_exponentiation(2,j,n);
            ll adtr=modular_exponentiation(ad,tr,n);
            if(adtr==(n-1)){
                prime=true;
                break; 
            }
        }
        if(prime==false) return false;
    }
    return true;    
}


int main(){
    ll n;
    cin>>n;
    if(miller_rabin(n)) cout<<"It is prime!"<<endl;
    else cout<<"It is not prime!"<<endl;
    
    return 0;
}