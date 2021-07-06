# COACH VIDY POMPELOP

## Utils

### ft_count

* Si je comprends bien, cette fonction doit trouver à quel index se trouve un char dans une string. Du coup le standard dans tous les languages c'est de l'appeler "find" plutôt que "count"
* Ces 2 blocs de code se ressemblent pas mal, c'est souvent un signe que tu peux faire la même chose avec un seul bloc
```c 
  // Bloc 1
 	if (c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
  // Bloc 2
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
 ```
 * Je vois que tu utilises `ft_count(s, '\0')` pour connaître la taille de `s`, c'est smart. Du coup c'est assez commun d'écrire une petite fonction comme celle qui suit pour t'éviter d'avoir à retaper le `'\0'` tout le temps mais surtout pour rendre ton code plus clair avec un nom de fonction plus explicite:
 ```c
	int ft_strlen(char *s)
	{
		return ft_count(s, '\0');
	}
 ``` 

### ft_strjoin

* Attention à ne pas oublier de checker si `s2` est `NULL` seule. `ft_strjoin("bla", NULL)` plante
* Le reste me paraît tout à fait raisonnable !
