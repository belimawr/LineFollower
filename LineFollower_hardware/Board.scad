
union(){
cube(size = [59,85,5], center = true);

translate([0, (56/2) - 5, 8]){
    cube(size = [10,10,20], center = true);
}

translate([0, -((56/2) - 5), 8]){
    cube(size = [10,10,20], center = true);
}

translate([0, -((56/2) +8), 7]){
    cube(size = [30,10,11], center = true);
}

translate([0, ((56/2) +8), 7]){
    cube(size = [30,10,11], center = true);
}
}