# COACH VIDY POMPELOP

## Utils

### ft_count

* Si je comprends bien, cette fonction doit trouver à quel index se trouve un char dans une string. Du coup le standard dans tous les languages c'est de l'appeler "find" plutôt que "count". ça peut paraître insignifiant mais avec l'experience, retrouver les mêmes noms pour les fonctions qui font la même chose dans tous les languages, ça aide !
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

### ft_substr

* Comme tu as besoin de connaître la taille de ta chaine de départ à plusieurs endroits, ça rendrait le code un peu plus clair de stocker le résultat de `ft_count(s, '\0')` dans une variable et d'utiliser cette variable à la place. Surtout si la variable a un joli nom explicite du type `str_length`
* Ici, il y a 2 choses qui sont mélangées: S'assurer que le paramètre `start` n'est pas en dehors de ta chaîne de départ, et calculer la taille de la sous chaîne que tu vas produire. Du coup il vaut mieux séparer ces 2 blocs. Surtout qu'avoir une `strlen` de 0 ça n'a pas beaucoup de sens pour le reste de la fonction et ton programme va executer du code pour rien genre un `malloc` de taille 1 juste pour mettre un `'\0'` dedans. Mieux vaut retourner `""` ou `NULL` direct
```c
if (start >= ft_count(s, '\0'))
	strlen = 0;
else if (len > (ft_count(s, '\0') - start))
	strlen = ft_count(s, '\0') - start;
else
	strlen = len;
```
* J'ai l'impression que t'utilises plutôt la notation `str[i]` que `*(str + i)` d'habitude. Les deux fonctionnent mais si t'as le choix, je te conseille de toujours garder la même. Ton code est plus facile à lire et à comprendre si les mêmes conventions sont utilisées partout (c'est l'intérêt d'une coding style d'ailleurs)
```c
// Cette notation
*(str + i) = *((char *)s + start + i);
// Ou celle-ci ?
str[i] = s[start + i];
```

## Get next line

* La première chose que je remarque c'est qu'il y a beaucoup de `free` dans ces fonctions et que c'est un coup à s'emmêler les pinceaux. Il vaut mieux réorganiser son code pour faire un seul free en toute fin de programme (si possible) plutôt qu'en plein milieu à chaque fois qu'il y a une erreur par exemple. L'idéal c'est même de free dans la même fonction que celle qui fait l'appel à l'util qui malloc
* La deuxième, c'est deux noms de variables: `var_to_free` et `tmp`. Avec la première je comprends direct ce que tu veux faire avec donc c'est un super nom. La deuxième, c'est l'inverse, je ne sais pas à quoi elle sert sans lire le code, et même après l'avoir lu je risque d'avoir du mal à être sûr. Pour toi qui a écrit le code, je suppose que c'est à peu près clair quand le code est frais, mais si tu reviens dessus 3 jours plus tard, tu vas aussi galérer un peu, et ça fait une charge cognitive de plus

### ft_read
* `char **tmp` n'est passé à cette fonction que dans le but d'appeler `free` dessus si le `read` rate. Étant donné qu'elle n'a pas d'utilité dans cette fonction, c'est un bon signe qu'elle ne devrait pas être passée en paramêtre du tout. Tu peux probablement faire le free dans `get_next_line` si `ft_read` retourne une erreur (ça rejoint mon point sur les `free` fait plus tôt)
* En retirant le free de `ft_read`, tu vas sûrement te rendre compte que `ft_read` est quasiment la même chose que `read` tout court. Je pense en effet que `ft_read` n'est pas une fonction que tu as besoin d'écrire, tu devrais pouvoir utiliser `read` directement dans `get_next_line`

### ft_complete_tmp
