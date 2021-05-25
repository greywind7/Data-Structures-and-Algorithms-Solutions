#include<bits/stdc++.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &expr) {
  vector<int> num;
  vector<char> exp;
  bool t = 0;
  for(const char &i:expr)
  {
    if(t)
    {
      exp.push_back(i);
      t = !t;
    }
    else
    {
      num.push_back(atoi(&i));
      t=!t;
    }
  }

  int n = num.size();
  // for(int i = 0; i < n; i++)
  //    cout << num[i] << " ";
  //    cout << endl;
  // for(int i = 0; i < exp.size(); i++)
  //    cout << exp[i] << " ";
  //    cout << endl;
  long long mx[n][n], mn[n][n];
  int ret_i = 0, ret_j = 0;
  while(1)
  {
    int i = ret_i, j = ret_j;
    // cout << "yea boiiiii" << endl;
    while(i < n && j < n)
    {
      // cout << "Wlooooop 222222" << endl;
      if(i == j)
      {
        mx[i][j] = num[i];
        mn[i][j] = num[i];
        i++;
        j++;
      }
      else if(j - i == 1)
      {
        mx[i][j] = eval(num[i], num[j], exp[i]);
        mn[i][j] = mx[i][j];
        i++;
        j++;
      }
      else
      {
        long mini = numeric_limits<long>::max() ;
        long maxi = numeric_limits<long>::min() ;
        for(int k = i; k < j ; k++)
        {
          long Ml = mx[i][k], Mh = mx[k+1][j];
          long ml = mn[i][k], mh = mn[k+1][j];
          char epp = exp[k];
          long a = eval(Ml,Mh,epp);
          long b = eval(Ml,mh,epp);
          long c = eval(ml,Mh,epp);
          long d = eval(ml,mh,epp);
          // cout << Ml << endl << Mh << endl << ml << endl << mh << epp<<k<< endl;
          mini = min(mini,min(a,min(b,min(c,d))));
          maxi = max(maxi,max(a,max(b,max(c,d))));
        }
        mx[i][j] = maxi;
        mn[i][j] = mini;
        i++;
        j++;
      }
    }
    ret_j++;
    // cout << ret_j << endl;
    if(ret_j == n)
      break;
  }

  return mx[0][--n];
}

bool isOperator(char op)
{
    return (op == '+' || op == '*');
}

long long printMinAndMaxValueOfExp(string exp)
{
    vector<int> num;
    vector<char> opr;
    string tmp = "";
 
    //  store operator and numbers in different vectors
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += exp[i];
        }
    }
    //  storing last number in vector
    num.push_back(atoi(tmp.c_str()));
 
    int len = num.size();
    int minVal[len][len];
    int maxVal[len][len];
 
    //  initializing minval and maxval 2D array
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            minVal[i][j] = INT_MAX;
            maxVal[i][j] = 0;
 
            //  initializing main diagonal by num values
            if (i == j)
                minVal[i][j] = maxVal[i][j] = num[i];
        }
    }
 
    // looping similar to matrix chain multiplication
    // and updating both 2D arrays
    for (int L = 2; L <= len; L++)
    {
        for (int i = 0; i < len - L + 1; i++)
        {
            int j = i + L - 1;
            for (int k = i; k < j; k++)
            {
                int minTmp = 0, maxTmp = 0;
 
                // if current operator is '+', updating tmp
                // variable by addition
                if(opr[k] == '+')
                {
                    minTmp = minVal[i][k] + minVal[k + 1][j];
                    maxTmp = maxVal[i][k] + maxVal[k + 1][j];
                }
 
                // if current operator is '*', updating tmp
                // variable by multiplication
                else if(opr[k] == '*')
                {
                    minTmp = minVal[i][k] * minVal[k + 1][j];
                    maxTmp = maxVal[i][k] * maxVal[k + 1][j];
                }
 
                //  updating array values by tmp variables
                if (minTmp < minVal[i][j])
                    minVal[i][j] = minTmp;
                if (maxTmp > maxVal[i][j])
                    maxVal[i][j] = maxTmp;
            }
        }
    }
 
    //  last element of first row will store the result
    return maxVal[0][len - 1];
}

void stress()
{
  int a =5;
  while(1){
    vector<char>X;
    char exp[] = {'*','+'};
    int xxx = 5; int t = 1;
    while(xxx--)
    {
      int x = rand() % 10 + 48;
      // cout << (char)x << exp[rand()%2] << endl;
      if(t){
        X.push_back((char)x);t--;}
      else{
        X.push_back(exp[rand()%2]);t++;}
      
    }  
    // cout << X[6];
    string s(X.begin(),X.end());
    int a = get_maximum_value(s);
    int b = printMinAndMaxValueOfExp(s);
    cout << s << " " << a << " " << b << endl;
    if(a != b){
      cout << s << endl << a << endl << b << endl;
      break;
    }
      
  }
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';

  // stress();
}
