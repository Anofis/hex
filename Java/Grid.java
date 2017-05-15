
package IHM;

public class Grid {
	protected int size;
	public Grid(int size){
		
		this.size = size;
		//creer grille en c
	}
	
	//Demander au c pour chaqu'une des coordonées sont etat
		public void print(){
			for(int i=0;i<size;i++)
				System.out.print("W ");
			System.out.println("W/B");
			for(int x=0;x<size;x++){
				
					
				for(int i=0;i<x+1;i++){
					System.out.print(" ");
				}
				System.out.print("B ");
				
				
				for(int y=0;y<size;y++){
					System.out.print(". ");
					//int x int y
				}
				System.out.print("B");

				System.out.print("\n");
				
				
			}
			for(int i=0;i<size+1;i++){
				System.out.print(" ");
			}
			System.out.print("B/W");
			for(int i=0;i<size;i++)
				System.out.print(" W");
		}
}
