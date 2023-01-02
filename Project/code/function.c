#include "function.h"

/***项目1 hello world! ***/
/**********************************/
void printHello(void)
{
    printf("hello world!\r\n");
}
/**********************************/


/***项目2 输出不小于用户定义的自然数的一个Fibonacci数 ***/
/**********************************/
//Fibonacci数计算
int Fib_CAL(int n)
{
    int fn;

    if(n<=2) fn = 1;
    else fn = Fib_CAL(n-2) + Fib_CAL(n-1);

    return fn;
}

//项目2主函数
void Fibonacci(void)
{
    int nn=0, fn=0, n=1, sc=11;

    printf("该程序输出不小于用户定义的自然数的一个Fibonacci数\r\n");

    printf("请输入所需检测的自然数：");
    scanf("%d", &nn);
    printf("\r\n");

    while(sc==11)
    {
        while ((fn=Fib_CAL(n)) < nn) n++;
        printf("检测的自然数nn=%d,对应的Fibonacci数fn=%d\r\n", nn, fn);

        printf("继续检测请输入11,退出请输入11以外的任意数:");
        scanf("%d", &sc);

        if(sc==11) 
        {
            printf("\r\n请输入所需检测的自然数:");
            scanf("%d", &nn);
            printf("\r\n");
        }
    }

    printf("\r\n感谢使用!\r\n");
}
/**********************************/


/***项目3 将输入复制到输出且删除多余空格 ***/
/**********************************/
void in_copy_out(void)
{
    int c=0; 
    _Bool nu=0;
    
    printf("请输入字符\r\n");
    while((c=getchar()) != EOF) 
    {
        if(c==' ')
        {
            if(!nu) putchar(c);
            nu=1;
        }
        else
        {
            nu=0;
            putchar(c);
        }
    }
}
/**********************************/


/***项目4 单词计数 ***/
/**********************************/
void word_count(void)
{
    int w_count=0, c=0;
    _Bool word=1;
    
    printf("请输入检测文本:\r\n");
    while((c=getchar()) != EOF) 
    {
        if(c==' ' || c=='\n' || c=='\t')
        {
            if(!word)
                word=1;
        }
        else if(word)
        {
            word=0;
            ++w_count;
        }
    }

    printf("word_count=%d\r\n",w_count);
}
/**********************************/


/***项目5 打印单词长度的直方图 ***/
/**********************************/
void word_len_hist(void)
{
    int w_count[20]={0}, w_m=0, c=0, i=0, k=0;
    _Bool word=1;
    
    printf("请输入检测文本,单词不允许超过20个,以Q为结束标志:\r\n");
    while((c=getchar()) != EOF) 
    {
        if(c==' ' || c=='\n' || c=='\t')
        {
            if(!word)
            {
                word = 1;            
                if(w_count[i]>w_m) w_m = w_count[i++];
                //w_count[++i];
            }
        }
        else
        {            
                ++w_count[i];
                if(word) word=0;            
        }
    }

    if(w_count[i]>w_m) w_m = w_count[i];

    printf("w_m=%d\r\n",w_m);
    
    for(int j=0; j<=i; j++)
    {
        for(k=0; k<=w_count[j]; k++)
            putchar('*'); //横向制表
        putchar('\n');
    }
    //for(int i=0; i<w_m; i++) {putchar('*');putchar('\v');} ////纵向制表
}
/**********************************/


/***项目6 日期计算器 ***/
/**********************************/
//x年所含闰年
#define LEAP_NUM(x)    ((x)/4-(x)/100+(x)/400)
#define XLEAP(x)       ((x)%100 && !((x)%4) || !((x)%400))

//年份变量声明
static struct time
{
    int year;
    int month;
    int day;
}date1,date2;

//每月所含天数
static int y_months[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                              {31,29,31,30,31,30,31,31,30,31,30,31}};

//年份字符串指针偏移量
static int p_move;

//字符转换整数
int str_int(char *str)
{
    char s,c;
    int  data;
    _Bool sign=1;

    str += p_move;

    for(c=s=*str++,p_move++; (s<'0' || s>'9'); s=*str++,p_move++)
    {
        c=s;
        if(s=='\0') return -1;
    }

    if(c=='-') sign=0;

    for(data=0; s>='0' && s<='9'; s=*str++,p_move++) data=10*data+s-'0';

    return sign?data:-data;
}

//将字符串所包含的年份信息转换为数字储存在年份结构体中
_Bool read_date(char *str)
{
    _Bool sign=1;

    if((date1.year = str_int(str))>0 && (date1.month = str_int(str))>0 && date1.month<=12 && (date1.day = str_int(str))>0 && date1.day<=y_months[XLEAP(date1.year)][date1.month]);
    else 
    {
        printf("第一个年份输入有误，请检查!\r\n");
        sign = 0;
    }

    if((date2.year = str_int(str))>0 && (date2.month = str_int(str))>0 && date2.month<=12 && (date2.day = str_int(str))>0 && date2.day<=y_months[XLEAP(date2.year)][date2.month]);
    else if(date2.month==(date2.year>0?-1:0) && !date2.day);
    else 
    {
        printf("第二个年份输入有误，请检查!\r\n");
        sign = 0;
    }

    return sign;
}

//将输入日期转换为该年相应天数
int year_to_date(struct time date)
{
    int day=date.day,l=0;

    l = date.year%100 && !(date.year%4) || !(date.year%400);

    for(int i=0; i<date.month-1;i++)
        day += y_months[l][i];

    return day;
}

//年份调换
void swop(int *year)
{
    struct time temp;
    int t;

    temp = date1;
    date1 = date2;
    date2 = temp;

    t = year[0];
    year[0] = year[1];
    year[1] = t;
}

//两年份间天数计算
int date_cal(int *year)
{
    int day=0,leap=0,year0;

    leap = LEAP_NUM(date2.year) - LEAP_NUM(date1.year);

     if(!(date1.year%100 && !(date1.year%4) || !(date1.year%400)))
     {
         year0 = 365-year[0];
         if(date2.year%100 && !(date2.year%4) || !(date2.year%400))
             --leap;
     }
            
     if(date1.year%100 && !(date1.year%4) || !(date1.year%400))
     {
         year0 = 366-year[0];
         if(!(date2.year%100 && !(date2.year%4) || !(date2.year%400)))
             ++leap;
     }

    if(leap<0) leap=0;
    
    day = (date2.year-date1.year?year[1] + year0:year[1] - year[0]);
    day += leap + (date2.year-date1.year?date2.year-date1.year-1:0)*365;

    return day;
}

//输入日期n天前(n为负)/后(n为正)的年份
void n_after_date_cal(void)
{
    int days =  date2.year; //为节省空间，将天数储存在第二个年份结构中，此操作是将天数复制给days
    date2 = date1;

    if(days>=0)
    {
        while(days >= 365 + (date2.month<3?XLEAP(date2.year):XLEAP(date2.year+1)))
        {
            days -= 365 + (date2.month<3?XLEAP(date2.year):XLEAP(date2.year+1));
            ++date2.year;
        }

        while(days >= y_months[XLEAP(date2.year)][date2.month-1])
        {
            days -= y_months[XLEAP(date2.year)][date2.month-1];
            ++date2.month;

            if(date2.month>12)
            {
                ++date2.year;
                date2.month -= 12;
            }
        }
        
        if(date2.day + days > y_months[XLEAP(date2.year)][date2.month-1])
        {
            date2.day += days -y_months[XLEAP(date2.year)][date2.month-1];
            ++date2.month;
        }
        else date2.day += days;

        if(date2.month>12)
        {
            ++date2.year;
            date2.month -= 12;
        }
    }
    else
    {
        while(-days >= 365 + (date2.month<3?XLEAP(date2.year-1):XLEAP(date2.year)))
        {
            days += 365 + (date2.month<3?XLEAP(date2.year-1):XLEAP(date2.year));
            --date2.year;
        }
        
        while(-days >= y_months[XLEAP(date2.year)][date2.month-2<0?0:date2.month-2])
        {
            days += y_months[XLEAP(date2.year)][date2.month-2<0?0:date2.month-2];
            --date2.month;

            if(date2.month<1)
            {
                --date2.year;
                date2.month += 12;
            }
        }
        
        if(date2.day <= -days)
        {
            --date2.month;

            date2.day += days + y_months[XLEAP(date2.year)][date2.month-1<0?0:date2.month-1];
        }
        else date2.day += days;

        if(date2.month<1)
        {
            --date2.year;
            date2.month += 12;
        }
    }
}

//主函数
void date_calculator(void)
{
    int year[2]={0,0}, day=0, days=0;
    char date[30];
    
    printf("请按年月日格式输入所需检测日期:\r\n");
    gets(date);
    
    if(read_date(date))
    {
        if(date2.month>0 && date2.day>0)
        {
            year[0] = year_to_date(date1);
            year[1] = year_to_date(date2);

            if(date1.year>date2.year || date1.year==date2.year && year[0]>year[1])
                swop(year);

            day = date_cal(year);

            printf("%d-%d-%d到%d-%d-%d相隔%d天\r\n",date1.year,date1.month,date1.day,date2.year,date2.month,date2.day,date,day);
        }
        else if(date2.month==(date2.year>0?-1:0) && !date2.day)
        {
            days = date2.year;

            n_after_date_cal();

            if(days>=0) printf("%d-%d-%d的%d天后是%d-%d-%d\r\n",date1.year,date1.month,date1.day,days,date2.year,date2.month,date2.day);
            else printf("%d-%d-%d的%d天前是%d-%d-%d\r\n",date1.year,date1.month,date1.day,-days,date2.year,date2.month,date2.day);
        }
    }
}
/**********************************/


/***项目7 计算器 ***/
/**********************************/
//字符串转实数,若非数字字符串则返回原字符
//缓冲数组
#define CBUFSIZE 20
static char bufc[CBUFSIZE];
static int bp;

//获取一个字符
char get_one_char(void)
{
    return bp>0?bufc[--bp]:getchar();
}

//压回一个字符
void ugetch(char c)
{
    if(bp>CBUFSIZE) printf("缓冲内存不足\r\n");
    else bufc[bp++]=c;
}

//递归求0.1的i次方
double dec(int i)
{
    double u;

    while(i-- > 0)
        u *=0.1;

    return u;
}

//字符串中提取非负实数,算数运算符和提取数学函数
double char_double(void)
{
    char s,t,f;
    double data;

    while((s=get_one_char())==' ' || s=='\t');

    switch (s)
    {
        case '+': return -'+'; //加法运算符
        case '-': return -'-'; //减法运算符或负号
        case '*': return -'*'; //乘法运算符
        case '/': return -'/'; //除法运算符
        case '^': return -'^'; //乘方运算符
        case '!': return -'!'; //阶乘运算符
        case '(': return -'('; //左括号
        case ')': return -')'; //右括号
        case '[': return -'['; //左中括号
        case ']': return -']'; //右中括号
        case '{': return -'{'; //左大括号
        case '}': return -'}'; //右大括号
        case 'e': return -'e'; //自然对数
        case 's':
            if((s=get_one_char())=='i' && (s=get_one_char())=='n') return -('s'+'i'+'n'); //正弦函数
            else if(s=='e' && (s=get_one_char())=='c') return -('s'+'e'+'c'); //正割函数
            else return -1; //输入错误
        case 'c':
        {
            if((t=s=get_one_char())=='o' && (s=get_one_char())=='s') return -('c'+'o'+'s'); //余弦函数
            else if(t=='o' && s=='t') return -('c'+'o'+'t'); //余切函数
            else if(t=='s' && (s=get_one_char())=='c') return -('c'+'s'+'c'); //余割函数
            else return -1; //输入错误
        }
        case 't':
            if((t=s=get_one_char())=='a' && (s=get_one_char())=='n') return -('t'+'a'+'n'); //正切函数
            else return -1; //输入错误
        case 'l':
            if((s=get_one_char())=='n') return -('l'+'n'); //自然对数为底的对数函数
            else if(s=='o' && (s=get_one_char())=='g') return -('l'+'o'+'g'); //对数函数
            else return -1; //输入错误
        case 'a':
            if((t=s=get_one_char())=='s' && (s=get_one_char())=='i' && (s=get_one_char())=='n') return -('a'+'s'+'i'+'n'); //反正弦函数
            else if(t=='c' && (f=s=get_one_char())=='o' && (s=get_one_char())=='s') return -('a'+'c'+'o'+'s'); //反余弦函数
            else if(t=='t' && (s=get_one_char())=='a' && (s=get_one_char())=='n') return -('a'+'t'+'a'+'n'); //反正切函数
            else if(t=='c' && f=='o' && s=='t') return -('a'+'c'+'o'+'t'); //反余切函数
            else return -1; //输入错误 
        case '\n': return -'\n'; //换行符表示输入结束
    }

    if(s<'0' || s>'9') return -1;
    
    for(data=0; s>='0' && s<='9'; s=get_one_char()) data = data*10 + s-'0';

    if(s=='.') for(int i=1,s=get_one_char(); s>='0' && s<='9'; i++,s=get_one_char()) data += + (s-'0')*dec(i);

    ugetch(s);

    return data;
}

//加减运算
double add_sub(double x, double y)
{

}

//乘除运算
double mul_div(double x, double y)
{

}

//阶乘运算
int factorial(int n)
{

}

//主函数
void calculator(void)
{

}
/**********************************/


