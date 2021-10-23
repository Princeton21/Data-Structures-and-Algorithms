# Simple program simulates Blackjack game.
#   Using method: Top-Down design, spiral development

from random import randrange

def main():
    printIntro()
    player_hand = player()
    dealer_hand = dealer()
    player_win, dealer_win = compare_between(player_hand, dealer_hand)
    printResult(player_hand, dealer_hand, player_win, dealer_win)


def printIntro():
    print("Blackjack (twenty-one) is a casino game played with cards.")
    print("the goal of game is to draw cards that total as close to 21 points, as possible")
    print("without going over( whose hand > 21 will bust). All face cards count as 10 points,")
    print("aces count as 1 or 11, and all other cards count their numeric value.")
    print("\nFirstly, your turn:")


def player():
    hand = []
    ans = "hit"
    hand.append(card())
    # Ask user whether Hit or Stand?
    # Condition True, if user want to Hit.
    while ans[0] == "h" or ans[0] == "H":
        hand.append(card())
        hand = eval_ace(hand)
        print("Your hand: {0} total = {1}".format(hand, sum(hand)))
        if bust(hand):
            break
        if blackjack(hand):
            break
        ans = input("Do you want to Hit or Stand (H or S)? ")
    return hand


def card():
    # get arbitrary card from 2 to 11.
    shuffle_card = randrange(2, 11 + 1)
    return shuffle_card


def eval_ace(hand):
    # Determine Ace = 1 or 11, relying on total hand.
    total = sum(hand)
    for ace in hand:
        if ace == 11 and total > 21:
            # at position, where Ace == 11, replace by Ace == 1.
            position_ace = hand.index(11)
            hand[position_ace] = 1
    return hand


def bust(hand):
    # Condition True: if the hand of player (or dealer) > 21.
    total = sum(hand)
    if total > 21:
        return True


def blackjack(hand):
    # Condition True: if the hand of player (or dealer) == 21.
    total = sum(hand)
    if total == 21:
        return True


def dealer():
    hand = []
    hand.append(card())
    while sum(hand) < 18:
        hand.append(card())
        hand = eval_ace(hand)
    return hand


def compare_between(player, dealer):
    total_player = sum(player)
    total_dealer = sum(dealer)
    player_bust = bust(player)
    dealer_bust = bust(dealer)
    player_blackjack = blackjack(player)
    dearler_blackjack = blackjack(dealer)
    player_win = 0
    dealer_win = 0
    # when player (dealer) bust.
    if player_bust:
        if not dearler_blackjack and total_dealer < 21:
            dealer_win += 1
    if dealer_bust:
        if not player_blackjack and total_player < 21:
            player_win += 1
    if player_bust and dealer_bust:
        if total_player > total_dealer:
            player_win += 1
        elif total_dealer > total_player:
            dealer_win += 1
        else:
            player_win == dealer_win
    # when player (dealer) get blackjack.
    if player_blackjack:
        player_win += 1
    if dearler_blackjack:
        dealer_win += 1
    if player_blackjack and dearler_blackjack:
        player_win == dealer_win
    # when total hand of player (dealer) < 21.
    if total_player < 21 and total_dealer < 21:
        if total_player > total_dealer:
            player_win += 1
        elif total_dealer > total_player:
            dealer_win += 1
        else:
            player_win == dealer_win
    return player_win, dealer_win


def printResult(player_hand, dealer_hand, player_win, dealer_win):
    print("\nWe have the result: ")
    print("Player has: {0} total = {1}".format(player_hand, sum(player_hand)))
    print("Dealer has: {0} total = {1}".format(dealer_hand, sum(dealer_hand)))
    print("player: {} | dealer: {}".format(player_win, dealer_win))


if __name__ == "__main__": main()
