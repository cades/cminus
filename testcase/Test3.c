/*Test 4 */
/* Can you handle unary operands? 
unary operands include - (minus) and ! (NOT) */ 

typedef int myint;


int negative(int a)
{
  return -a;
}

float nagative_float(int a, float b)
{
  /* allow same var name in different scope */
  float result;

  /* allow implicit conversion*/
  result = -(a * b);

  return result;
}

float myfunc3(int a[][2], float b)
{
  float ret;

  ret = -a[0][0] + b;

  return ret;
}

int main()
{
  int arr[4];
  int arr2[3][2];
  float arr3[5];
  int div, sum;
  int loopvar=0;
  float result;
  myint n;
  
  

  result = 4;
  while( n < result )
  {
    arr[n] = n;
    n = n + 1;
  }

  for (loopvar = 1; loopvar <= n ; loopvar = loopvar + 1)
  {
    sum = sum + loopvar;
  }

  write("enter a divider");
  div = read();

  if (div != 0 && sum)
  {
    result = sum / div;
    if ((result >= 10) && !div)
    {
      arr[0] = negative(sum);
    }
    else
    {
      arr[1] = negative_float(sum, 1.5);    
    }
  }
  else
  {
    return 0; 
  }

  arr[2] = arr[0] * arr[1] + result + sum;  

  result = myfunc3(arr2, arr3[2]);

  /* allow overloaded(type int or float) "write" function calls */
  write(sum);
  write(result);

  return 0;
}
