import java.util.Scanner;

public class RockPaperScissors {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		// To keep track of no. of games played, losses and wins
		int wins = 0;
		int loss = 0;
		int played = 0;

		System.out.println("Rock Paper Scissors game.");
		System.out.println("-----------------------------------------------------------------------");
		System.out.println();
		System.out.println("If you want to quit the game, type in quit");
		System.out.println("Enter your move. Type in rock, paper or scissors :  ");
		String move = scan.next(); // users move

		// If user chose to quit the game.
		while (!move.equals("quit")) {
			// If user's move is not rock, paper or scissor, then print invalid move
			if (!move.equals("rock") && !move.equals("paper") && !move.equals("scissors"))
				System.out.println("Your move is not valid");
			// If move is valid, game is continued
			else {
				played++;
				// Generating computer's move thru Random
				int rand = (int) (Math.random() * 3);
				String comp = ""; // System's move
				if (rand == 0)
					comp = "rock";
				else if (rand == 1)
					comp = "paper";
				else
					comp = "scissors";

				// Print out System's move
				System.out.println("Opponent's move : " + comp);

				// Calculate user won, lost or tied
				if (move.equals(comp))
					System.out.println("It's a tie");
				else if ((move.equals("rock") && comp.equals("scissors")) ||
						(move.equals("paper") && comp.equals("rock")) ||
						(move.equals("scissors") && comp.equals("paper"))) {
					System.out.println("You won!!");
					wins++;
				} else {
					System.out.println("You lost, better luck next time");
					loss++;
				}
			}
			System.out.println();

			// Print out wins and losses
			System.out.println("Number of games played: " + played);
			System.out.println("Number of games won: " + wins);
			System.out.println("Number of games lost: " + loss);
			if (wins > loss)
				System.out.println("You are in the lead!");
			else if (loss > wins)
				System.out.println("Opponent is in the lead. You can do it!");
			else
				System.out.println("You and your opponent have tied.");

			// Prints out options
			System.out.println();
			System.out.println("If you want to quit the game, type in quit");
			System.out.println("Enter your move. Type in rock, paper or scissors :  ");
			move = scan.next();
			if (move.equals("quit"))
				System.out.println("Thank you for playing the game.");
		}
	}
}
