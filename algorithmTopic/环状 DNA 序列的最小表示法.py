def solution(dna_sequence):
    n = len(dna_sequence)

    rotations = [dna_sequence[i:] + dna_sequence[:i] for i in range(n)]

    return min(rotations)

# 测试样例
if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("ATCA") == "AATC")
    print(solution("CGAGTC") == "AGTCCG")
    print(solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG")
