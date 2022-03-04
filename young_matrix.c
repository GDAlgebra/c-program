
int extract_min(int* young_matrix, int row, int colomn) {
	int min = *young_matrix, j = colomn - 1;
	for (int i = 0; i < row; i++) {
		for (; young_matrix[i * colomn + j] == 0 && j >= 0; j--);
		if (j == 0)
			break;
		if (young_matrix[i * colomn + j] < min)
			min = young_matrix[i * colomn + j];
		i++;
	}
	return min;
}

void insert_youngmatrix(int insertkey, int* young_matrix, int row, int colomn) {
	int i = 0, j = colomn - 1;
	for (; *(young_matrix + i * colomn + j) != 0 && i < row; i++);
	for (; *(young_matrix + i * colomn + j) == 0 && j >= 0; j--);
	j++;
	young_matrix[i * colomn + j] = insertkey;
	while (*(young_matrix + (i - 1) * colomn + j) < *(young_matrix + i * colomn + j) && i > 0) {
		*(young_matrix + i * colomn + j) = *(young_matrix + (i - 1) * colomn + j);
		*(young_matrix + (i - 1) * colomn + j) = insertkey;
		i--;
	}
	while (*(young_matrix + i * colomn + (j - 1)) < *(young_matrix + i * colomn + j) && j > 0) {
		*(young_matrix + i * colomn + j) = *(young_matrix + i * colomn + (j - 1));
		*(young_matrix + i * colomn + (j - 1)) = insertkey;
		j--;
	}
	return;
}
