#include<cstdio>

using namespace std;

class MyClass
{
    int a[100];
public:
    MyClass(int n);
    void LinearSearch(int x,int n);
    void BubbleSort(int n);
    void BinarySearch(int x,int n);
};

MyClass::MyClass(int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void MyClass::LinearSearch(int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("%d is found at position %d\n",x,i+1);
            return;
        }
    }
    printf("%d is not found\n",x);
}

void MyClass::BinarySearch(int x,int n)
{
    int lo=0,hi=n-1,mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]==x)
        {
            printf("%d is found\n",x);
            return;
        }
        else if(a[mid]>x)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    printf("%d is not found\n",x);
}

void MyClass::BubbleSort(int n)
{
    bool flag;
    while(1)
    {
        flag=false;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                flag=true;
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
}

int main()
{
    int n,x;
    scanf("%d",&n);
    MyClass Obj(n);
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&x);
        Obj.LinearSearch(x,n);
    }
    Obj.BubbleSort(n);
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&x);
        Obj.BinarySearch(x,n);
    }
    return 0;
}