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