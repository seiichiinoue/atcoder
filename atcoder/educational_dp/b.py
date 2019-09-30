def main():    
    N, K = map(int, input().split())
    H = [int(i) for i in input().split()]

    dp = [0 for _ in range(N)]
    dp[0] = 0
    for i in range(1, N):
        dp[i] = min([dp[j] + abs(H[j] - H[i]) for j in range(max(0, i-K), i)])
    print(dp[N-1])

if __name__ == '__main__':
    main()
