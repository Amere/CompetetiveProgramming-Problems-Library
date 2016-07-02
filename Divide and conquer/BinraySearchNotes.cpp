
/* BS using STL Library */
auto it = lower_bound(v.begin(),v.end(),4); // 1 2 3 /4/ 4 4 4 5 6 7
auto it = upper_bound(v.begin(),v.end(),4); // 1 2 3 4 4 4 /4/ 5 6 7
*it ->> idx
//NOTE if it==v.end(); then the value is not found;


/* Ordinary BS just finding the answer in an increasing sequence */
int BS(int arr[],int start,int end, int val){
  while (end>=start) {
    mid = start + (end-start)/2;
    if(arr[mid]>val) end = mid-1;
    else
        if(arr[mid]<val) start = mid+1;
        else return mid;
  }
  return -1;
}

/* BS first match according to a function result or to a bool result */
int BSfirstMatch(int start,int end,int val){
  while (true) {
    if(end-start == 5){
      int idx = -1;
      for (int i = 0; i < 5; i++) {
        if(f(start)==val){
          idx = start;
          break;
        }
        start++;
      }
      return idx;
    }
    int mid = start + (end-start)/2;
    if(f(mid)>val)  end = mid-1;
    else if(f(mid)<val) start = mid+1;
          else end = mid;
  }
}


/* BS last match according to a function result or to a bool result */
int BSlastMatch(int start,int end,int val){
  while (true) {
    if(end-start == 5){
      int idx = -1;
      for (int i = 0; i < 5; i++) {
        if(f(end)==val){
          idx = end;
          break;
        }
        end--;
      }
      return idx;
    }
    int mid = start + (end-start)/2;
    if(f(mid)>val)  end = mid-1;
    else if(f(mid)<val) start = mid+1;
          else start = mid;
  }
}



/* BS over double */
//EPS is and important value and should be given in the problem

//first concept may lead to wrong answers according to EPS
double BSdouble(double start,double end,double val){ //this may iterate from 100-500 according to your EPS value
  for (int i = 0; i < 80; i++) {
    int mid = start + (end-start)/2.0;
    if(fabs(f(mid)-val)<EPS) return mid //found;
    else{
      if (f(mid)>val) {
        end = mid;
      }else{
        start = mid;
      }
    }
  }
  return -1;
}
