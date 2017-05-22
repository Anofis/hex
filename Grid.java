import java.util.Scanner;


public class Grid {
	private Game g;
	protected int size;
	protected int board[] = new int [10001];
	protected int lastX;
	protected int lastY;
	private Scanner sc;

	public Grid(int size,Game g,int[] board,int lastX,int lastY){
		this.size = size;
		this.board = board;
		this.lastX=lastX;
		this.lastY=lastY;
		this.g= g;
	}


	public Grid(int size,Game g){
		this.g = g;
		this.size = size;
		lastX = size;
		lastY = size;
		board[0]= size;
		for(int i=1;i<size+1;i++)
		{
			board[i]=0;
		}
		for(int i= (size*size)+1;i<10001;i++){
			board[i]=5;
		}
	}

	/**
	 * Affiche la grille en ASCII
	 */
	public void print(){
		for(int i=0;i<size;i++)
			System.out.print("W  ");
		System.out.println(" W/B");
		for(int x=0;x<size;x++){


			for(int i=0;i<x+1;i++){
				System.out.print(" ");
			}
			System.out.print("B  ");


			for(int y=0;y<size;y++){
				System.out.print(coordToChar(x,y));
			}
			System.out.print(" B");

			System.out.print("\n");


		}
		for(int i=0;i<size+1;i++){
			System.out.print(" ");
		}
		System.out.print("B/W");
		for(int i=0;i<size;i++)
			System.out.print("  W");
		System.out.print("\n");
	}

	/**
	 * Converti les coordonnees en " CHAR "
	 * @param x La coordonnee en abscisse
	 * @param y La coordonnee en ordonnees
	 * @return String Une chaine de la forme " CHAR "
	 */
	public String coordToChar(int x,int y){
		if(x==lastX && y==lastY){
			switch(this.board[size*x+(y+1)])
			{
			case 2:
				return " X ";
			case 1:
				return " 0 ";
			default:
				return " . ";
			}
		}
		switch(this.board[size*x+(y+1)])
		{
		case 2:
			return " * ";
		case 1:
			return " o ";
		default:
			return " . ";
		}
	}


	/**
	 * Converti les coordonnees en int
	 * @param x La coordonnee en abscisse
	 * @param y La coordonnee en ordonnees
	 * @return int Un int qui correspond a la couleur de la case (0 vide,1 blanc,2 noir)
	 */
	public int coord(int x,int y){

		return size*x+(y+1);
	}


	/**
	 * Demande au joueur de placer un pion sur la grille
	 */
	public void pawn() {

		System.out.println("\n");
		System.out.println("(-1 annuler dernier coup, -2 quitter, \n-3 abandonner,-4 relancer une partie)\n\nX ? ");
		sc = new Scanner(System.in);
		int x = sc.nextInt();
		if(x>-1){
			System.out.println("Y ?");
			int y = sc.nextInt();
			if(board[coord(x,y)]==0){
				this.board[coord(x,y)] = g.nowPlaying();
				g.nbShots++;
				lastX =x;
				lastY =y;
				if(g.nbShots%2==0 && g.nbShots!=0){
					g.nbTurns++;
				}
			}
			else{
				System.out.println("\033[33m"+"Erreur impossible de mettre un pion sur cette case"+"\033[0m");
				pawn();
			}
		}
		if(x == -1){
			if(lastX ==size || lastY ==size ){
				System.out.println("\033[33m"+"Il n'y a aucun coup a annuler.."+"\033[0m");
				pawn();
			}
			else{
				board[coord(lastX,lastY)]=0;
				if(--g.nbShots %2 !=0){
					g.nbTurns --;
				}
			}
			lastX=size;
			lastY=size;

		}
		if(x==-2){
			System.out.println("Voulez vous sauvegarder ? (o/n)");
			sc.nextLine();
			if(sc.nextLine().equals("o")){
				System.out.println("Sauvegarde !");
				g.Saving_game();

			}
			g.end = true;

		}
		if(x==-3){
			System.out.println("Etes vous sur de vouloir abandonner ? (o/n)");
			sc.nextLine();
			if(sc.nextLine().equals("o")){
				g.end = true;
				g.surrend = true;
			}
			else{
				pawn();
			}
			
		}
		if(x==-4){
			System.out.println("Etes vous sur de vouloir relancer une partie ? (o/n)");
			sc.nextLine();
			if(sc.nextLine().equals("o")){
				g.end = true;
				g.relaunch = true;

			}
			else{
				pawn();
			}
		}
		if(x<-4)
			pawn();
	}





	/**
	 * Converti les coordonnees en "CHAR "
	 * @param x La coordonnee en abscisse
	 * @param y La coordonnee en ordonnees
	 * @return String Une chaine de la forme "CHAR "
	 */
	public String coordToChar_saving(int x,int y){
		/*if(x==lastX && y==lastY){
		switch(this.board[size*y+(x+1)])
		{
		case 2:
			return "X ";
		case 1:
			return "0 ";
		default:
			return ". ";
		}
	}*/
		switch(this.board[size*y+(x+1)])
		{
		case 2:
			return "* ";
		case 1:
			return "o ";
		default:
			return ". ";
		}
	}
}

