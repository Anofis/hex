import java.io.IOException;
import java.util.Scanner;

public class Hex {

	private static Scanner sc;
	public static Game menu() throws IOException{
		Game game;
		System.out.println("Voulez vous restaurer une ancienne partie (o/n)");
		sc = new Scanner(System.in);
		if(sc.nextLine().equals("o")){
			Save save = new Save("Saving_Game.txt");
			game = save.Restore();
		}
		else{
			game = new Game();
		}
		return game;
	}
	public static void main(String[] args) throws IOException {
		Game game = menu();
		game.tips();
		for(;!game.end &&InterfaceWithC.victory(game.grid.board) != 1;){//&&InterfaceWithC.victory(game.grid.board) != 1
			game.print();
			game.play();
		}
		if(!game.end && !game.surrend && !game.relaunch){
			System.out.print("\033[42m"+"\n\nVictoire du joueur ");
			if(game.nowPlaying()==1)
				System.out.println("noir"+"\033[0m");
			else
				System.out.println("blanc"+"\033[0m");
			System.out.println("\nVoici le plateau final : \n");
			game.grid.print();
		}
		if(game.end && !game.surrend && !game.relaunch){
			System.out.println("\033[32m"+"A bientot !"+"\033[0m");
		}
		if(game.end && game.surrend && !game.relaunch){
			System.out.print("\033[42m"+"\n\nAbandon du joueur ");
			if(game.nowPlaying()==2)
				System.out.println("noir"+"\033[0m");
			else
				System.out.println("blanc"+"\033[0m");
			System.out.print("\033[42m"+"\nVictoire du joueur ");
			if(game.nowPlaying()==1)
				System.out.println("noir"+"\033[0m");
			else
				System.out.println("blanc"+"\033[0m");
			System.out.println("\nVoici le plateau final : \n");
			game.grid.print();
		}
		if(game.end && game.relaunch && !game.surrend){
			System.out.println("-NOUVELLE PARTIE-");
			main(null);
		}
	}

}
