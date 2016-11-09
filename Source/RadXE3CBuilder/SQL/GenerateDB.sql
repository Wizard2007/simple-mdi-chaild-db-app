
/****** Object:  Table [dbo].[tbl_Master]    Script Date: 21.07.2016 15:33:40 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[tbl_Master](
	[IdMaster] [int] IDENTITY(1,1) NOT NULL,
	[MasterName] [varchar](32) NOT NULL,
	[CreateDate] [datetime] NOT NULL,
 CONSTRAINT [PK_tbl_Master] PRIMARY KEY CLUSTERED 
(
	[IdMaster] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

ALTER TABLE [dbo].[tbl_Master] ADD  CONSTRAINT [DF_tbl_Master_MasterName]  DEFAULT ('') FOR [MasterName]
GO

ALTER TABLE [dbo].[tbl_Master] ADD  CONSTRAINT [DF_tbl_Master_CreateDate]  DEFAULT (getdate()) FOR [CreateDate]
GO

ALTER TABLE [dbo].[tbl_Master]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Master_tbl_Master] FOREIGN KEY([IdMaster])
REFERENCES [dbo].[tbl_Master] ([IdMaster])
GO

ALTER TABLE [dbo].[tbl_Master] CHECK CONSTRAINT [FK_tbl_Master_tbl_Master]
GO

ALTER TABLE [dbo].[tbl_Master]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Master_tbl_Master1] FOREIGN KEY([IdMaster])
REFERENCES [dbo].[tbl_Master] ([IdMaster])
GO

/****** Object:  Table [dbo].[tbl_Detail]    Script Date: 21.07.2016 15:33:46 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[tbl_Detail](
	[IdDetail] [int] IDENTITY(1,1) NOT NULL,
	[DetailName] [varchar](32) NOT NULL,
	[IdMaster] [int] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
 CONSTRAINT [PK_tbl_Detail] PRIMARY KEY CLUSTERED 
(
	[IdDetail] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

ALTER TABLE [dbo].[tbl_Detail] ADD  CONSTRAINT [DF_tbl_Detail_DetailName]  DEFAULT ('') FOR [DetailName]
GO

ALTER TABLE [dbo].[tbl_Detail] ADD  CONSTRAINT [DF_tbl_Detail_CreateDate]  DEFAULT (getdate()) FOR [CreateDate]
GO

ALTER TABLE [dbo].[tbl_Detail]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Detail_tbl_Detail] FOREIGN KEY([IdMaster])
REFERENCES [dbo].[tbl_Master] ([IdMaster])
GO

ALTER TABLE [dbo].[tbl_Detail] CHECK CONSTRAINT [FK_tbl_Detail_tbl_Detail]
GO

