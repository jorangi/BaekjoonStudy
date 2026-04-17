int solution(int n) {
    int answer = 0;
    bool even = n%2==0;
    for(int i = 1; i <= n; i++)
    {
        if(even && i%2==0) answer += i*i;
        else if(!even && i%2==1) answer += i;
    }
    return answer;
}