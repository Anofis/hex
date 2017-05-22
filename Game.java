import java.util.Scanner;

import java.io.PrintWriter;
import java.io.IOException;

public class Game {
	public int nbTurns=0;
	public int nbShots=0;
	private int begin;
	private int second;
	public Grid grid;
	public boolean end;
	public boolean surrend;
	public boolean relaunch;
	private Scanner sc;
	
	public Game(int nbTurns,int nbShots,int begin,int size,int[] board,int lastX,int lastY){
		this.end = false;
		this.surrend = false;
		this.relaunch = false;
		this.nbShots = nbShots;
		this.nbTurns = nbTurns;
		this.begin = begin;
		if (begin == 2)
			this.second =1;
		else
			this.second =2;
		this.grid = new Grid(size,this,board,lastX,lastY);
	}
	

	public Game(){
		this.end = false;
		this.surrend = false;
		this.relaunch = false;
		System.out.println("Veuillez saisir la taille du plateau de jeu (Saisir 0 pour 11x11, < 100) ..");
		sc = new Scanner(System.in);
		int size = sc.nextInt();
		sc.nextLine();
		if(size <0 || size >100)
		{
			System.out.println("Veuillez entrer un nombre compris entre 0 et 100");
			size = sc.nextInt();
			sc.nextLine();
		}
		if(size<1){
			size= 11;
		}
		
		Grid grid = new Grid(size,this);
		this.grid = grid;
		String b = "E";
		for(; !b.equalsIgnoreCase("w") && !b.equalsIgnoreCase("b");){
			System.out.println("Quel joueur commence ? (B/W)");
			b = sc.nextLine();
		}
		if(b.equalsIgnoreCase("b")){
			begin=2;
			second=1;
		}
			
		else{
			begin=1;
			second=2;
		}
			
	}

	public void tips(){
		System.out.println("Pour placer un pion saisir ses coordonnes en X/Y compris dans [0,taille[ ");
		System.out.println("  --> Y");
		System.out.println("X|");
		System.out.println(" v");
	}
	
	/**
	 * Demande au joueur de placer un pion dans ce jeu
	 */
	public void play(){
		grid.pawn();
	}
	
	/**
	 * Renvoie un int en fonction du joueur qui est entrain de jouer
	 * @return int 1 pour le joueur blanc 2 pour le joueur noir
	 */
	public int nowPlaying(){
		if(nbShots %2 ==0){
			if(begin==2)
				return 2;
			else
				return 1;
		}
		else{
			if(second==2)
				return 2;
			else
				return 1;
		}
	}
	
	/**
	 * Affiche l'interface (nb de coups, nb de tours, joueur qui joue, grille) 
	 */
	public void print(){
		
		System.out.println("\nNombre de tours joues : "+nbTurns);
		
		System.out.println("Nombre de coups joues : "+nbShots);
		
		System.out.print("C'est au joueur");
		if(nowPlaying()==2)
			System.out.print(" noir (*) ");
		else
			System.out.print(" blanc (o) ");
		System.out.print("de jouer\n\n");
		grid.print();
		
	}
	
	/**
	 * Sauvegarde le jeu actuel dans un fichier
	 */
	public void Saving_game(){
		try{
	 	   	PrintWriter writer = new PrintWriter("Saving_Game.txt", "UTF-8");
		    writer.println("\\hex");
		   	writer.println("\\dim "+grid.size);
			writer.println("\\board");
			for(int y=0;y<grid.size;y++){
				for(int x=0;x<grid.size;x++){
					writer.print(grid.coordToChar_saving(x,y));
				}
				writer.println();
			}
			writer.println("\\endboard");
			writer.println("\\game");
			if( nowPlaying() == 1)
					writer.print("\\play * ");
			else
					writer.print("\\play o ");
			writer.println(grid.lastX+" "+grid.lastY);
			writer.println("\\endgame");
			writer.println("\\endhex");
			writer.close();
		} catch (IOException e) {
			System.err.println("Problem writing to the file Saving_Game.txt");
		}
	}

	
}
