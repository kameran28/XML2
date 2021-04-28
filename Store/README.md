# Notes

> All the tinyxml2 code is in the `tinyxml2` folder
> All the data is in the `data/store.xml`
> All our source code is in `src` folder

# How to run

> Drag and drop store file in Visual studio code.

> In terminal choose "New command prompt"

> To change directory to programs execcute below in the command prompt
    
    cd src

> To run the executable `storecli.exe` just execute the below in the command prompt

    storecli.exe


> To show products

    > To show all products execute

        storecli.exe show


> To add a product execute

    storecli.exe add name="Tasty chicken" price="12.34" description="Best chicken in the world" image_url="https://imgs.com/chicken"

    Once you execute this, you'll see the product in store.xml with a unique and random id


> To edit a product with an id

    storecli.exe edit id="1779" name="Edited" description="You have edited"

    Pass any properties you want to edit for that particular product and it will be updated in `data/store.xml`


> To remove a product execute

    storecli.exe remove id="1184"

    Use the id from the store.xml of the product to remove that particular product

s
>  To search particular product

    To show the product with an id

        storecli.exe show id="1819"

    > To show all products containing a search term like "chicken"

        storecli.exe show part_name="Eggs"
        
  > To       

