import sys

def read_and_clean(filename):
    # read a file and return contents as a single string by removing spaces newlines
    try:
        with open(filename,'r') as f:
            text = f.read()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found")
        sys.exit(1)
    # removing spaces and newlines
    return text.replace(" ","").replace("\n","")

def edit_distance(s, t):
    # O(nm) time and O(nm) space
    n = len(s)
    m = len(t)
    dp = [[0]*(m+1) for _ in range(n+1)]  
    # base cases
    for i in range(n+1):
        dp[i][0] = i
    for j in range(m+1):
        dp[0][j] = j

    for i in range(1,n+1):
        for j in range(1,m+1):
            if s[i-1] ==t[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                # insertion , deletion, substitution
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])
    return dp[n][m]

# How to run this python file : python CS24BTECH11047.py file1.txt file2.txt
def main():
    file1 = sys.argv[1]
    file2 = sys.argv[2]
    s = read_and_clean(file1)
    t = read_and_clean(file2)
    distance = edit_distance(s, t)
    print(distance)

if __name__ == "__main__":
    main()