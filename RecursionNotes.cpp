// How to avoid stack problems
// 1- If must do it in recursion, then avoid any unnecessary local data. Move to global as possible
// 2- Move to iterative procedure
// 3- Implement your own stack calls!
// 4- using vectors inside the recursion is fine as it always refrences to the heap
// but using arrays will always takes from the stack size.
void generateTernary_myStack(int len)
{
    stack< pair<int, string> > st;  // create stack consist of recursion state
    st.push( make_pair(len, "") );

    while(!st.empty())
    {
        int len = st.top().first;
        string cur = st.top().second;
        st.pop();

        if(len == 0) {
            cout<<cur<<"\n";
            continue;
        }

        st.push(make_pair(len-1, cur + "0"));
        st.push(make_pair(len-1, cur + "1"));
        st.push(make_pair(len-1, cur + "2"));

    }
}



// Print all possible permutations of numbers 0, 1, 2, ...n-1
void perm(int i, int n, int vis[], int cur[])
{
   if(i == n)
   {
       for (int j = 0; j < n; ++j)
           cout<<cur[j];
       cout<<"\n";
       return;
   }

   for (int j = 0; j < n; ++j) if(!vis[j])
   {
       vis[j] = 1;
       cur[i] = j;

       perm(i+1, n, vis, cur);

       vis[j] = 0;
   }
}



// print N choose M combinations
void comb(int i, int n, int m, int cur[], int curLen)
{
    if(curLen == m)
    {
        for (int j = 0; j < m; ++j)
            cout<<cur[j];
        cout<<"\n";
        return;
    }

    if(i == n)  // we reached end, and have current combination is not correct
        return;

    // take it
    cur[curLen] = i;
    comb(i+1, n, m, cur, curLen+1);

    // don't take it
    comb(i+1, n, m, cur, curLen);
}
