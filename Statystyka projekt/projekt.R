library(readxl)
data1 <- read_xlsx("D:/4 semestr/Statystyka/projekt1/projekt1.xlsx", sheet = 2)

install.packages("dprep")
mode <- function(x) {
  ux <- unique(x)
  ux[which.max((tabulate(match(x,ux))))]
}

age <- data1$Age
games <- data1$Games
gpr <- data1$`Goals per min`
goals <- data1$Goals
name <- data1$Name
nat <- data1$Nationality
leag <- data1$League

column_names <- c("Min", "1st Quadrille", "Median", "Mean", "3rd Quadrille", "Max","Mode","Range" ,"Variance","Standard Deviation")

age_array <- array(c(summary(age), mode(age), max(age)-min(age), var(age), sd(age)), 
                   dim = c(10,1,1), 
                   dimnames = list(column_names, "AGE"))

games_array <- array(c(summary(games), mode(games), max(games)-min(games), var(games), sd(games)), 
                   dim = c(10,1,1), 
                   dimnames = list(column_names, "GAMES"))

goals_array <- array(c(summary(goals), mode(goals), max(goals)-min(goals), var(goals), sd(goals)), 
                   dim = c(10,1,1), 
                   dimnames = list(column_names, "GOALS"))

round(age_array, 1)
round(games_array, 1)
round(goals_array, 1)

hist(age,
     main = "Histogram Age",
     xlab = "Age",
     xlim = c(15, 40),
     ylim = c(0,35),
     col = c("cyan", "lightblue"),
     breaks = seq(from=0, to = 40, by = 2.5)
)

hist(games,
     main = "Histogram Games",
     xlab = "Games",
     xlim = c(20, 60),
     ylim = c(0,40),
     col = c("pink","violet"),
     breaks = seq(from=0, to = 60, by = 5)
)

hist(goals,
     main = "Histogram Goals",
     xlab = "Goals",
     xlim = c(10, 50),
     ylim = c(0,50),
     col = c("lightgreen", "darkgreen"),
     breaks = seq(from=0, to = 50, by = 4)
)

hist(gpr,
     main = "Histogram Goals per minute",
     xlab = "Goals per min",
     xlim = c(0,350),
     ylim = c(0,40),
     col = c("gold", "yellow"),
     breaks = seq(from=0, to = 300, by = 25)
)


boxplot(age,
        main = "Boxplot Age",
        ylab = "Age",
        range = 0,
        col = "lightblue",
        ylim = c(19,40)
        )

boxplot(games,
        main = "Boxplot Games",
        ylab = "games",
        range = 0,
        col = "violet",
        ylim = c(20,60)
)

boxplot(goals,
        main = "Boxplot Goals",
        ylab = "Goals",
        range = 0,
        col = "lightgreen",
        ylim = c(15,50)
)

boxplot(gpr,
        main = "Boxplot Goals per minute",
        ylab = "Goals per minute",
        range = 0,
        col = "gold",
        ylim = c(50,300)
)

table(nat)  
nat_plot <-
  c("Angola", "Argent.", "Au-lia.", "Austria", "Belgium", "Bosnia", "Brasil", "Ca-roon", "Canada", "Col-bia",                  
    "Congo", "Croatia", "Czech.", "Egypt", "England", "France", "Gabon", "Germany", "Greece", "Holland", "Iran", "Israel",
    "Italy", "Iv.Coast", "Kosovo", "Mexico", "Morocco", "Nigeria", "Norway","Poland", "Portugal","Russia", "Scotland",
    "Senegal", "Serbia", "Korea", "Spain","Sweden", "Swietz.", "Turkey", "Ukraine", "Uruguay", "Zambia"  )
 
barplot(table(nat), horiz = T, 
        las = 1, 
        xlim = c (0,12), 
        col = c("blue","green"), 
        names.arg = nat_plot,
)

n_argentina <- length(which(nat == "Argentina"))
n_uruguay <- length(which(nat == "Uruguay"))
n_brasil <- length(which(nat== "Brasil"))
n_senegal <- length(which(nat == "Senegal"))
n_gabon <- length(which(nat == "Gabon"))
n_columbia <- length(which(nat== "Columbia"))


n_vec <- c(n_argentina, n_uruguay, n_brasil, n_senegal, n_gabon, n_columbia)
n_labels <- c("Argentina", "Uruguay", "Brasil", "Senegal", "Gabon", "Columbia")
n_percent <- round(100*n_vec/sum(n_vec), 1)


pie(n_vec,
    n_percent,
    main = "Percent Pie Chart for Nationality - outside the EU",
    col = c("#99ffff", "#009999", "#00e600", "red", "#6699ff","gold")
    )
legend("topleft", n_labels, cex = 0.8, fill = c("#99ffff", "#009999", "#00e600", "red", "#6699ff","gold"))

l_spain <- length(which(leag == "Spain"))
l_england <- length(which(leag == "England"))
l_germany <- length(which(leag == "Germany"))
l_italy <- length(which(leag == "Italy"))
l_france <- length(which(leag == "France"))

l_austria <- length(which(leag == "Austria"))
l_belgium <- length(which(leag == "Belgium"))
l_czech <- length(which(leag == "Czech Republic"))
l_holland <- length(which(leag == "Holland"))
l_portugal <- length(which(leag == "Portugal"))
l_qatar <- length(which(leag == "Qatar"))
l_russia <- length(which(leag == "Russia"))
l_scotland <- length(which(leag == "Scotland"))
l_turkey <- length(which(leag == "Turkey"))
l_ukraine <- length(which(leag == "Ukraine"))


l_vec <- c(l_spain, l_england, l_germany, l_italy, l_france)
l_labels <- c("Spain", "England", "Germany", "Italy", "France")
l_percent <- round(100*l_vec/sum(l_vec), 1)

table(leag)
barplot(table(leag),
        ylim = c(0,20),
        col = "lightsteelblue"
        )

pie(l_vec,
    l_percent,
    main = "Pie Chart for Leagues",
    col = c("gold", "#e60000", "black", "#009933", "#003cb3")
)
legend("topleft", l_labels, cex = 0.8, fill = c("gold", "#e60000", "black", "#009933", "#003cb3"))

l_vec_all <- c(l_spain, l_england, l_germany, l_italy, l_france, l_austria,l_belgium, l_czech, l_holland,
               l_portugal, l_qatar, l_russia, l_scotland, l_turkey, l_ukraine)
l_labels_all <- c("Spain", "England", "Germany", "Italy", "France", "Austria", "Belgium", "Czech", "Holland",
                  "Portugal", "Qatar", "Russia", "Scotland", "Turkey", "Ukraine")
l_percent_all <- round(100*l_vec_all/sum(l_vec_all), 1)

pie(l_vec_all,
    l_labels_all,
    main = "Pie Chart for all leagues",
    col = rainbow(15)
)

pie(l_vec_all,
    l_percent_all,
    main = "Percent Pie Chart for all leagues",
    col = rainbow(15)
)
legend("topleft", l_labels_all, cex = 0.8, fill = rainbow(15))
