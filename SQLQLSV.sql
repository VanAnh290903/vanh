create database QLSV
use QLSV
go
create table tblKhoa 
(
fk_sMaK nvarchar(10) not null primary key,
sTenK nvarchar(15) not null,
iSDT int,
sDiachi nvarchar(15),
)
alter table tblKhoa
add unique(sTenK)
go
create table tblLop
(
sMalop nvarchar not null primary key,
sTenlop nvarchar not null,
fk_sMaK nvarchar(10) not null,

)
alter table tblLop add unique(sTenlop)
go
ALTER TABLE tblLop
ADD FOREIGN KEY (fk_sMaK) REFERENCES tblKhoa(fk_sMaK); 
go
create table tblsinhVien
(
sMaSV nvarchar(10) not null primary key,
sTenSV nvarchar(15) not null,
sGioiTinh nvarchar(4) not null check( sGioiTinh in('Nam', N'Nữ')),
dNgaySinh date not null check(year(getdate())- year(dNgaySinh)>=18),
sMalop nvarchar not null,
)
go 
alter table tblsinhVien
ADD FOREIGN KEY (sMalop) REFERENCES tblLop(sMalop); 
go
create table tblMon
(
sMaM nvarchar(10) not null primary key;
sTenM nvarchar(10) not null,
iSoTC int,

)
go
create table tblDiem
(
sMaSV nvarchar(10) not null,
sMaMon nvarchar(10) not null,
dNgayHoc date,
fDiemCC float not null check(fDiemCC >=0 and fDiemCC<=10),
fDiemGK float not null check(fDiemGK >=0 and fDiemGK<= 10),
fDiemThi float not null check(fDiemThi >=0 and fDiemThi<=10),
constraint khoa_chinh primary key(sMaSV,sMaMon,dNgayHoc),
);

go

