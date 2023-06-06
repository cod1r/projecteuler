if __name__ == '__main__':
    # At some point, for a digit sequence that has more than 6 digits and all of it's digits are 9 (the highest)
    # If all of those digits are taken to the fifth power, the rate at which more 9's are needed exceeds the rate that the sum of those 9's raised
    # to the fifth power increases which means any digit sequence that has more than six digits won't affect the problem.
    MAX_NUM = 9**5 * 6
    ans = 0
    uniq = set()
    for n in range(9, 2, -1):
        for start in range(n**5, MAX_NUM):
            string = str(start)
            s = 0
            for i in range(len(string)):
                s += int(string[i]) ** 5
            if s == start:
                uniq.add(s)
    for n in uniq:
        ans += n
    print(ans)
