Final results:

```
clothing --- 4.5603e+09 --- 911487	
video games --- 4.56011e+09 --- 913326	
baby products --- 4.54144e+09 --- 907186	
beauty products --- 4.53387e+09 --- 906417	
gardening tools --- 4.53188e+09 --- 905841	
automotive --- 4.52986e+09 --- 904962	
music instruments --- 4.51229e+09 --- 902389	
furniture --- 4.50399e+09 --- 900244	
electronics --- 4.49753e+09 --- 903266	
pet supplies --- 4.48874e+09 --- 896724	
stationery --- 4.48179e+09 --- 898265	
home appliances --- 4.47389e+09 --- 895815	
sports equipment --- 4.46939e+09 --- 894287	
groceries --- 4.46692e+09 --- 895470	
footwear --- 4.46557e+09 --- 894424	
jewelry --- 4.46382e+09 --- 893980	
office equipment --- 4.46356e+09 --- 892370	
toys --- 4.46245e+09 --- 892741	
books --- 4.45762e+09 --- 890948	
health & wellness --- 4.45408e+09 --- 890475	
```

Time measurements:
- 1 mapper (no `idmapper.cpp`, no `idreducer.cpp`)
    - Regular run (8 splits): 48.408872295 sec
    - Every file splitted (16 splits): 48.411416791 sec
    - First file splitted into 4 (18 splits): 50.406687792 sec
- 8 mappers:
    - Regular run (8 splits): 50.729562055 sec
    - Every file splitted (16 splits): 50.815924028 sec
    - First file splitted into 4 (18 splits): 51.797463383 sec
- 16 mappers:
    - Regular run (8 splits): 51.724646618 sec
    - Every file splitted (16 splits): 51.845694392 sec
    - First file splitted into 4 (18 splits): 52.755290305 sec
