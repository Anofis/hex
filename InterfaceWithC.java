

class InterfaceWithC {
	
	static {
		System.loadLibrary("InterfaceWithC");
		}
		/**
		 * Defini si un joueur a gagne ou non
		 * @param board Le tableau representant les cases
		 * @return int 1 si un joueur a gagne 0 sinon
		 */
		public static native int victory(int board[]);
		
}
