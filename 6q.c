/********************************************

* Name: ABD ALKAREAM JAYOUSI ID:305209561 *

* Name: Haytham Agbariah ID: 204451843 *

* Assignment number : 6 *

* Exercise number : 3 *

*******************************************/
#include<stdio.h>
#define ERROR 1


    /* from q1 : calcaulte the mudolo */
    int mudolo(int num,int divider){
        if(num<divider)
            {
                return num;
        }
        mudolo(num-divider,divider);
        }
        /* this function will calculate the gcd(a,b) a=first_num,b=second_num */
        int gcd(int first_num,int second_num){
            if(second_num==0)
                {
                    return first_num;
            }
           return gcd(second_num,mudolo(first_num,second_num));
}
/* q3 starting : */
int mult_ab(int a,int b){
    if (a==1){
        return b;
        }
    a--;
    return b+(mult_ab(a,b));
    }
/*me7lkem num b2 mekbelt num wtemp= num -1 "bhana7a eno num zoge" */
int div2(int num,int temp){
    if (mudolo(num,temp)==0){
        return temp;
        }
    return div2(num,temp-1);
    }
/*bodkem ma hazka hamksemalet shel 2 : <= num , mat7el count=0 ..num 7eyove..count mt7el b 0..temp mat7el  b 1*/
int log2(int num,int temp,int count){
    if(num<temp){
        return count-1;
        }
    if(num==temp){
        return count;
        }
    count++;
    temp+=temp;
    return log2(num,temp,count);
    }
/*mekabelet num 7eyove wbbase 7eyove wma7zera base be7zkat ha num*/
int power(int num,int base){
    if(num==0)
        return 1;
    num--;
    return mult_ab(base,power(num,base));
    }


int dec_to_bin(int num){
    int l,p,temp;
    if(num<=1){
        return num;
        }
    l=log2(num,1,0);
    p=power(l,2);
    if(p==num){
        return power(l,10);
        }
    temp=dec_to_bin(mudolo(num,p));
    return power(l,10)+temp;
    }

int main()

{
    int num,div,checker,checker1 ;
    printf("Please inert 2 numbers : ");
    /* checking the input  */
    checker=scanf("%d",&num);
    checker1=scanf("%d",&div);
    if(checker != 1 || checker1 != 1)
    {
        printf("Error");
        return ERROR ;

    }
    if(num < 0 || div <= 0)
    {
        printf("Error");
        return ERROR ;
    }
   if(div == 0 || num == 0)
    {
        printf("Error");
        return ERROR ;
    }
    /* printing the result : */
    else
        {
            printf("%d",dec_to_bin(gcd(num,div)));
    return 0 ;
    }

return 0 ;
}

