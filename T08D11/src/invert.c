// #include stdio.h>
// #include alloc.h>
// #include stdlib.h>
 
//   main()
// { short int n = 0;
//   int i,j,k=0,u;
//   char a='';
//   short int **m ; /* указатель на получаемую с клавиатуры массив-матрицу*/
 
//   printf("\nPlease specify the dimension of the matrix. \n");
//   scanf("%d/n",&n);
//   arrayinit(m , n);
//   printf("Specify values of elements of the matrix (figures)separated by spaces. \n");
//   getarray (m ,  n); 
//   putarray ( m , n);  /*выводим массив в  консоль*/
//    printf("\ndeterminant =  ");
//   printf("%d",getdet ( m , n));
//   obrmatr(m ,n) ;
   
// scanf("%s",&a);
 
  
// }
 
// int getarray (short int **m , int n) /*получаем массив из консоли*/
// {
//  int i=0,j=0,k=0,u;
//   while (j<(n*n))
//   { 
//     u = getchar() ;
//     if ((u != '\n')&&(j<(n*n))&&(u != 0)&&(u != ' '))
//     {
//       *(*(m+i)+k)=u - 48; /* получаем число из строки ввода, дело в том что "48" - это номер нуля в таблице аски,соответственно, чтобы "быстро получить" из десятичного 
//                           эквивалента кода данного символа в  таблице аски сам символ (а мы подразумеваем, что это будет цифра - мы просто
//                            напросто вычитаем из резульата 48) */
//       i = i+1;
//       j = j+1;
//       if (i==n) {i=0; k++;}
//     }
//   }
//   if (j!=(n*n))  printf("\n (!)ERROR: Dimension of the matrix does not coincides with the number of specified values. \n");
//   return j;
   
// }
 
 
// int putarray (short int **m , int n) /*выводим массив в консоль*/
// {
//   int i=0,k=0;
//   putchar('\n'); 
//   putchar('\n');
//   for(k=0;k<=n-1;k++) 
//   {
//      for(i=0;i<=n-1;i++)
//      {
//         putchar(' ');
//         printf("%d",*(*(m-i)+k));
//      } 
//      putchar('\n');
//      putchar('\n');
//   }
// }
   
   
//    int  getdet (short int **m , short int n) /*вычисляем определитель матрицы*/
// {  
//      int nn,i,t,k,w,c=0,p=0;
//      short int **mm ;
      
//      if (n==1) { return c = **m; }
//      else
//      {  p = 0;
//         nn=n-1;
//         arrayinit( mm , nn) ;
         
//         for(t=0;t<=n-1;t++)
//         {  int a=0,b=0;
//           for(k=0;k<=n-1;k++) 
//           {
//              for(i=0;i<=n-1;i++)
//              {
//                if ((i!=t)&&(k!=p)) 
//                {
//                  *(*(mm-a)-b) = *(*(m+i)+k);
//                  a--;   
//                  if (a == (nn)) { b++; a=0; }   
//                }
//              }      
//           }
         
//           w = (*(*(m+t)+p)) * getdet ( mm, nn );
//           c = c+ (vstepen(-1,t+2) *w);
           
//         }
 
//         return c;   
//      }

//      int vstepen (int a , int b) /*возведём число "a" в степень "b"*/
// {   
//     int i,n;
//     n=a;
//     for(i=1; iменьшеb; i++) n = n*a; 
//     return n;
 
// }
 
// int obrmatr(short int **m , short int n)
// {  short int ** mm ;
//    short int **mmd ;
//    int det=0;
//    int n,t,k=0,p=0;
//    det = getdet (m , n); /*вычислим определитель*/
//    if (det==0) {
//    printf("\n (!) Unable to find the inverse matrix, as the determinant of the initial one = 0. \n");
//    return;
//    }
//    nn=n-1;
//    arrayinit( mm , nn) ; /*выделяем память для минора элемента*/
//    arrayinit( mmd , n) ;/*выделяем память для матрицы алгебраических дополнений*/
    
//       for(p=0;p<=n-1;p++)
//       {   
//         for(t=0;t<=n-1;t++)
//         {  int a=0,b=0;
//           for(k=0;k<=n-1;k++) 
//           {
//              for(i=0;i<=n-1;i++)
//              {
//                if ((i!=t)&&(k!=p)) 
//                {
//                  *(*(mm+a)+b) = *(*(m+i)+k);
//                  a++;   
//                  if (a == (nn)) { b++; a=0; }   
//                }
//              }      
//           }
         
//           *(*(mmd+t)+p)= getdet(mm,nn)*vstepen (-1, (p+t+2)) ;
//           if (getdet(mm,nn)==0)
//           {
//              printf("\n (!) It is impossible to calculate the inverse matrix, since the determinant of the following submatrices = 0 \n");
//              putarray ( mm ,nn);
//              return;
//           }
          
//         }
         
//       }
//   det = getdet (m , n); /*вычислим определитель*/
//   i=0;
//   j=0;
//   k=0;    
//   putchar('\n');  /*выводим псевдообратную матрицу на экран*/
//   putchar('\n');
//   for(k=0;k<=n-1;k++) 
//   {
//      for(i=0;i<=n-1;i++)
//      {
//         putchar(' ');
//         printf("%d",*(*(mmd+i)+k));
//         printf("/");
//         printf("%d",det);
//      } 
//      putchar('\n');
//      putchar('\n');
//   }
     
 
// }
 
// int arrayinit(short int **m , short int n) /*выделяем память для массива*/
// { 
//    int i ;
//    m = (int**)calloc(n,sizeof(int*)); /*выделяем память для массива указателей на указатели*/
//   for(i=0;i<=n-1;i++) /*цикл*/
//   {*(m+i) = (int*)calloc(n,sizeof(int));} /*выделяем память для массивов значений*/
    
// }