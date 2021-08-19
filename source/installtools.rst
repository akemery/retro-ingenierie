Install APKTOOL
===============

Cette partie est prise de la documentation de `ubuntu <https://doc.ubuntu-fr.org/apktool>`_

Pré-requis
----------

#. Disposer des droits d'administration.

#. Disposer d'une connexion à Internet configurée et activée.

#. Avoir java 7 (JRE 1.7) installé

#. Connaissances basique de Android SDK, AAPT and smali

Installation
------------


#. Télécharger `Linux wrapper <https://raw.githubusercontent.com/iBotPeaches/Apktool/master/scripts/linux/apktool>`_ script (Clic droit, enregistrer le lien sous apktool)
    
#. Télécharger `apktool-2 (derniere version ici) <https://bitbucket.org/iBotPeaches/apktool/downloads/>`__

#. Renomer le fichier .jar téléchargé en apktool.jar

#. Déplacer les deux fichiers (apktool.jar & apktool) dans /usr/local/bin (root requis)

#. Rendez les deux fichiers executable (chmod +x)

#. Lancez apktool via le Terminal avec la commande apktool

Utilisation
-----------

.. code-block:: bash

	apktool
	

Décodage
--------

L'option de décodage peut être appelé par les argument ``d`` ou ``decode`` comme montré ci-dessous 

.. code-block:: bash

	apktool d foo.jar # décode foo.jar dans le répertoire foo.jar.out
	apktool decode foo.jar # décode foo.jar dans le répertoire foo.jar.out
	apktool d bar.apk # décode bar.apk dans le répertoire bar
	apktool decode bar.apk # décode bar.apk dans le répertoire bar
	apktool d bar.apk -o baz # décode bar.apk dans le répertoire baz


Construction
------------

L'option de re/construction peut être appelée par les argument ``b`` ou ``build`` comme montré ci-dessous:

.. code-block:: bash

	apktool b foo.jar.out # builds foo.jar.out folder into foo.jar.out/dist/foo.jar file

	apktool build foo.jar.out # builds foo.jar.out folder into foo.jar.out/dist/foo.jar file

	apktool b bar # builds bar folder into bar/dist/bar.apk file

	apktool b . # builds current directory into ./dist

	apktool b bar -o new_bar.apk # builds bar folder into new_bar.apk 
	


Frameworks
----------

Comme vous le savez probablement, les applications Android utilisent du code et des ressources qui se trouvent sur le système d'exploitation Android lui-même. Ceux-ci sont connus comme des Framework et Apktool s'appuie sur ceux-ci pour correctement décoder et construire des apks. Les Frameworks peuvent êtres installés avec if ou install-framework, de plus deux paramètres autorisent un contrôle plus précis sur la manière dont les fichiers sont nommés et stockés.

.. code-block:: bash

    -p, –frame-path <dir> - Stocke le framework dans <dir>
    -t, –tag <tag> - Tag frameworks utilisant <tag>
    

.. code-block:: bash

	apktool if framework-res.apk
	I: Framework installé dans: 1.apk  # pkgId du framework-res.apk détermines le numéro (lequel est 0x01)

	apktool if com.htc.resources.apk
	I: Framework installé dans: 2.apk  # pkgId de com.htc.resources est 0x02

	apktool if com.htc.resources.apk -t htc
	I: Framework installé dans: 2-htc.apk  # pkgId-tag.apk

	apktool if framework-res.apk -p foo/bar
	I: Framework installé dans: foo/bar/1.apk

	apktool if framework-res.apk -t baz -p foo/bar
	I: Framework installé dans: foo/bar/1-baz.apk
	

ltrace
======

``ltrace`` est un programme qui exécute simplement la commande spécifiée jusqu'à ce qu'elle se termine. Il
intercepte et enregistre les appels de bibliothèque dynamiques qui sont appelés par le processus exécuté et
les signaux qui sont reçus par ce processus. Il peut également intercepter et imprimer les appels système
exécutés par le programme.

.. code-block:: console

	emery@mininet-vm:~/Documents/2021/uac/reverse_engineering/src/codes/binaires$ ltrace ./ch1.bin 
	__libc_start_main(0x804869d, 1, 0xff8f9d54, 0x8048750 <unfinished ...> puts("################################"...############################################################)                             = 61
	puts("##        Bienvennue dans ce cha"...##        Bienvennue dans ce challenge de cracking        ##)                             = 61
	puts("################################"...############################################################)                             = 62
	printf("Veuillez entrer le mot de passe "...)                           = 34
	malloc(2)                                                               = 0x8f8a5b0
	getchar(2, 0xf7f2f000, 0xff8f9c98, 0xf7d94759Veuillez entrer le mot de passe : lll)                          = 108
	realloc(0x8f8a5b0, 2)                                                   = 0x8f8a5b0
	getchar(0x8f8a5b0, 2, 0xff8f9c98, 0xf7d94759)                           = 108
	realloc(0x8f8a5b0, 3)                                                   = 0x8f8a5b0
	getchar(0x8f8a5b0, 3, 0xff8f9c98, 0xf7d94759)                           = 108
	realloc(0x8f8a5b0, 4)                                                   = 0x8f8a5b0
	getchar(0x8f8a5b0, 4, 0xff8f9c98, 0xf7d94759)                           = 10
	strcmp("lll", "123456789")                                              = 1
	puts("Dommage, essaye encore une fois."...Dommage, essaye encore une fois.)                             = 33
	+++ exited (status 0) +++
	
	
strace
======

Dans le cas le plus simple, strace exécute la commande spécifiée jusqu'à ce qu'elle se termine. Il intercepte et enregistre les appels système qui sont appelés par un processus et les signaux qui sont reçus par un processus. Le nom de chaque appel système, ses arguments et sa valeur de retour sont imprimés sur erreur standard ou dans le fichier spécifié avec l'option -o.

	
.. code-block:: console

	strace  ./ch1.bin
