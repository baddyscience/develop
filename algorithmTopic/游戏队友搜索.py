def solution(id, num, array):
    match_count = {}
    
    for player1, game in array:
        for player2, game2 in array:
            if game == game2 and player1 != player2:
                if (player1, player2) not in match_count:
                    match_count[(player1, player2)] = 0
                match_count[(player1, player2)] += 1
    
    teammates = set()
    for (p1, p2), count in match_count.items():
        if p1 == id and count >= 2:
            teammates.add(p2)
        elif p2 == id and count >= 2:
            teammates.add(p1)
    
    teammates = sorted(teammates)
    
    return teammates

if __name__ == "__main__":
    # Add your test cases here
    print(
        solution(
            1,
            10,
            [
                [1, 1],
                [1, 2],
                [1, 3],
                [2, 1],
                [2, 4],
                [3, 2],
                [4, 1],
                [4, 2],
                [5, 2],
                [5, 3],
            ],
        )
        == [4, 5]
    )