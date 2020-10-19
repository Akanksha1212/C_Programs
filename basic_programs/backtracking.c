backtrack(int a[], int k, int n) {
	int c[MAXCANDIDATOS];  /* Candidatos para a próxima posição */
	int ncandidatos;       /* Número de candidatos para a próxima posição */
	int i;                 /* Contador */
	
	if (e_uma_solucao(a, k, n)) {
		processar_solucao(a, k, n);
	} else {
		k = k + 1;
		construir_candidatos(a, k, n, c, &ncandidatos);
		for (i=0; i<ncandidatos; i++) {
			a[k] = c[i];
			backtrack(a, k, n);
			if (acabou) return;
		}
	}
}
