ll cat [27];
		cat[0] = 1;
		for(int i = 1; i <= 26; ++i)
			cat[i] = cat[i-1] * (i<<1) * ((i<<1) - 1) / (i * (i + 1));
