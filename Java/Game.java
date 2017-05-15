package IHM;

import java.util.Scanner;

public class Game {
	public int nbTurns=0;
	public int nbShots=0;
	private int begin;
	private int second;
	public Grid grid;
	
	public Game(){
		System.out.println("Veuillez saisir la taille du plateau de jeu (Saisir 0 pour 11x11) ..");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		sc.nextLine();

		if(size<1){
			size= 11;
		}
		Grid grid = new Grid(size);
		this.grid = grid;
		String b = "E";
		for(; !b.equalsIgnoreCase("w") && !b.equalsIgnoreCase("b");){
			System.out.println("Quel joueur commence ? (B/W)");
			b = sc.nextLine();
		}
		sc.close();
		if(b.equalsIgnoreCase("b")){
			begin=2;
			second=1;
		}
			
		else{
			begin=1;
			second=2;
		}
			
	}
	
	public void play(int x,int y){
		if(nbShots % 2==0){
			//Changer couleur de x,y en begin
		}
		else
		{
			//changer couleur de x,y en second
		}
		nbShots++;
		if(nbShots%2 ==0){
			nbTurns++;
		}
	}
	
	public void print(){
		System.out.println("Nombre de tours joués : "+nbTurns);
		
		System.out.println("Nombre de coups joués : "+nbShots);
		
		System.out.print("C'est au joueur");
		if(nbShots %2 ==0){
			if(begin==2)
				System.out.print(" noir ");
			else
				System.out.print(" blanc ");
		}
		else{
			if(second==2)
				System.out.print(" noir ");
			else
				System.out.print(" blanc ");
		}
		System.out.print("de jouer\n\n");
		grid.print();
	}
	
}
