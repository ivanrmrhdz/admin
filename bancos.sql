-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 06-12-2018 a las 12:25:26
-- Versión del servidor: 5.7.23
-- Versión de PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `bancos`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cuentas`
--

DROP TABLE IF EXISTS `cuentas`;
CREATE TABLE IF NOT EXISTS `cuentas` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `numcuenta` int(8) NOT NULL,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `apellido` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `saldo` varchar(10) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=26 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `cuentas`
--

INSERT INTO `cuentas` (`id`, `numcuenta`, `nombre`, `apellido`, `saldo`) VALUES
(1, 11223312, 'Marlon Alberto ', 'Palacios Rodriguez', '1749.71'),
(2, 44575675, 'Maria Fernandez', 'Alejandra Guerrero', '203.23'),
(3, 77654466, 'Herber Antonio', 'Frenandez Guerrero', '300.80'),
(4, 44574233, 'Carlos Ivan', 'Martinez Martinez', '4140.34'),
(5, 44556765, 'Carlos Manuel', 'Romero Hernandez', '100.50'),
(6, 44556677, 'Fernando Alejandro', 'Palomo Benitez', '240.50'),
(7, 33178923, 'Herber Antonio', 'Portillo Cuadrado', '30.12');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
