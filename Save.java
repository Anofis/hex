import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
public class Save {
	private String path;
	private int size;
	private int board[] = new int [10001];
	private int lastX;
	private int lastY;
	private int nbTurns;
	private int nbShots;
	private int begin;

	public Save(String path) throws IOException{
		this.path=path;
		Loading_game();
	}

	/**
	 * Charge le jeu
	 * @throws IOException
	 */
	public void Loading_game() throws IOException{
		Reader reader = new FileReader(path);
		char buff [] = new char[10000];
		int data = reader.read();
		int j=0;
		int Last=0;
		nbTurns=0;
		nbShots=0;
		size=0;
		lastX=0;
		lastY=0;
		boolean boardInit = false;
		while(data != -1){
			char dataChar = (char) data;

			if(dataChar == '\\'){
				j=0;

			}
			buff[j++]=dataChar;
			if(eq(buff,"\\dim") && size ==0){
				for(int l=0;l<2&&data!=-1;l++)
					data = reader.read();
				if(data!=-1){
					size = data -48;
					data = reader.read();
					if(data-48 < 10 && data-48 >-1){
						size = size*10 + data -48;
						data = reader.read();
						if(data-48 < 10 && data-48 >-1){
							size = size*10 + data -48;
						}
					}
				}
			}
			if(eq(buff,"\\board") && !boardInit){
				int pos=0;
				board[pos++]=size;

			    dataChar = (char) data;
				int a=0;
				while(dataChar !='\\'){


					buff[a++]=dataChar;



					data = reader.read();
					dataChar = (char) data;

				}
				
				for(int y=0;y<a;y++){
					switch(buff[y]){
					case '*':
						board[pos++]= 2;
						if(++nbShots != 0 && nbShots %2 ==0)
							nbTurns++;
						break;
					case 'o':
						board[pos++]= 1;
						if(++nbShots != 0 && nbShots %2 ==0)
							nbTurns++;
						break;
					case '.':			
						board[pos++]= 0;
						break;
					default:
						break;
					}  
					
				
				}
				boardInit=true;
			}
			if(eq(buff,"\\play ")&&lastY==0 && lastX==0){
				data = reader.read();
				if(data!=-1)
					dataChar = (char) data;
				switch(dataChar){
				case '*':
					Last= 2;
					break;
				case 'o':
					Last= 1;
					break;					
				}
				for(int l=0;l<2&&data!=-1;l++)
					data = reader.read();
				if(data!=-1)
					lastX = data-48;
				for(int l=0;l<2&&data!=-1;l++)
					data = reader.read();
				if(data!=-1)
					lastY = data-48;
				if((lastY==size) || (lastX == size)){

					lastY=size;
					lastX=size;
					
				}
			}


			data = reader.read();


		}
		reader.close();
		if(Last!=0){
			if(nbShots %2 ==0)
				if(Last ==1)
					begin =2;
				else
					begin =1;
			else
				begin =Last;
		}

	}

	/**
	 * Retourne un Game avec les proprietes de la sauvegarde
	 * @return Game Le jeu restaure
	 */
	public Game Restore(){

		return new Game(nbTurns,nbShots,begin,size,board,lastX,lastY);

	}

	/**
	 * teste l'egalite des caracteres d'un tableau et d'une chaine
	 * @param buff Un tableau de Char
	 * @param s Une chaine
	 * @return boolean 1 si egal 0 sinon
	 */
	private boolean eq(char[] buff,String s ){
		for(int i=0;i<s.length();i++){
			if(buff[i]!=s.charAt(i))
				return false;
		}
		return true;
	}

	
}
