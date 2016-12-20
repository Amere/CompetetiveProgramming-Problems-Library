getline(cin,s);
istringstream iss(s);
int a;
iss>>a;
while (iss>>a) {
    a--;
    grid[i][a] = 1;
}
}
